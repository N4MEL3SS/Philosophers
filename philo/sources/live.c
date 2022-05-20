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

void	eating(t_phil_data *phil)
{
	pthread_mutex_lock(phil->r_fork);
	pthread_mutex_lock(phil->l_fork);
	ft_wait(phil, phil->time_eat, 1);
	pthread_mutex_unlock(phil->r_fork);
	pthread_mutex_unlock(phil->l_fork);
}

void	sleeping(t_phil_data *phil)
{
	ft_wait(phil, phil->time_sleep, 0);
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
