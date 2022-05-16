/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:06:57 by celadia           #+#    #+#             */
/*   Updated: 2022/05/16 17:07:34 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_phil_data *phil)
{
	long		time;

	pthread_mutex_lock(phil->r_fork);
	pthread_mutex_lock(phil->l_fork);
	time = ft_get_time() - phil->start_time;
	ft_msg(phil, YELLOW, L_FORK, time);
	ft_msg(phil, YELLOW, R_FORK, time);
	ft_msg(phil, CYAN, EAT, time);
	phil->last_meal = ft_get_time();
	ft_wait(phil->data->time_eat);
	pthread_mutex_unlock(phil->r_fork);
	pthread_mutex_unlock(phil->l_fork);
}

void	sleeping(t_phil_data *phil)
{
	ft_msg(phil, BLUE, SLEEP, \
		ft_get_time() - phil->start_time);
	ft_wait(phil->data->time_sleep);
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
	pthread_detach(phil->thread);
	while (phil->data->flag)
	{
		eating(phil);
		if (phil->must_eat > 0)
			--phil->must_eat;
		sleeping(phil);
		thinking(phil);
	}
	return (NULL);
}
