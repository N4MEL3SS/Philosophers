/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:06:57 by celadia           #+#    #+#             */
/*   Updated: 2022/05/17 18:58:12 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * if (mutex_check(phil))
 * 		return ;
 *
int		mutex_check(t_phil_data *phil)
{
	if (pthread_mutex_trylock(phil->l_fork))
	{
		pthread_mutex_unlock(phil->r_fork);
		ft_msg(phil, YELLOW, OUT_FORK, ft_get_time() - phil->start_time);
		usleep(50);
		return (1);
	}
	return (0);
}
*/

void	ft_msg(t_phil_data *phil, char *color, char *msg, long time)
{
	pthread_mutex_lock(phil->output_block);
	printf(TEXT, color, time, RESET, phil->phil_id, color, msg, RESET);
	pthread_mutex_unlock(phil->output_block);
}

void	eating(t_phil_data *phil)
{
	pthread_mutex_lock(phil->r_fork);
	pthread_mutex_lock(phil->l_fork);
	pthread_mutex_lock(phil->data_block);
	phil->last_meal = ft_get_time();
	pthread_mutex_unlock(phil->data_block);
	ft_msg(phil, YELLOW, L_FORK, phil->last_meal - phil->start_time);
	ft_msg(phil, YELLOW, R_FORK, phil->last_meal - phil->start_time);
	ft_msg(phil, CYAN, EAT, phil->last_meal - phil->start_time);
	ft_wait(phil->time_eat);
	pthread_mutex_unlock(phil->r_fork);
	pthread_mutex_unlock(phil->l_fork);
}

void	sleeping(t_phil_data *phil)
{
	ft_msg(phil, BLUE, SLEEP, \
		ft_get_time() - phil->start_time);
	ft_wait(phil->time_sleep);
}

void	thinking(t_phil_data *phil)
{
	ft_msg(phil, MAGENTA, THINK, \
		ft_get_time() - phil->start_time);
}

void	*start_act(void *phil_thread)
{
	t_phil_data	*phil;

	phil = (t_phil_data *)phil_thread;
//	pthread_detach(phil->thread);
	if (phil->must_eat == 0)
		return (NULL);
	while (phil->exit_flag)
	{
		eating(phil);
		pthread_mutex_lock(phil->data_block);
		if (phil->must_eat > 0)
			--phil->must_eat;
		pthread_mutex_unlock(phil->data_block);
		sleeping(phil);
		thinking(phil);
	}
	return (NULL);
}
