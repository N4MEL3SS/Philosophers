/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:06:57 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 12:13:48 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_phil_data *phil)
{
	long		time;

	pthread_mutex_lock(phil->r_fork);
	pthread_mutex_lock(phil->l_fork);
	if (phil->data->flag)
	{
		time = ft_get_time() - phil->start_time;
		ft_msg(phil, YELLOW, L_FORK, time);
		ft_msg(phil, YELLOW, R_FORK, time);
		ft_msg(phil, CYAN, EAT, time);
	}
	phil->last_meal = ft_get_time();
	ft_wait(phil->data->time_eat);
}

void	sleeping(t_phil_data *phil)
{
	pthread_mutex_unlock(phil->r_fork);
	pthread_mutex_unlock(phil->l_fork);
	if (phil->data->flag)
		printf(TEXT, BLUE, ft_get_time() - phil->start_time, RESET, \
			phil->phil_id, BLUE, SLEEP, RESET);
	ft_wait(phil->data->time_sleep);
}

void	thinking(t_phil_data *phil)
{
	if (phil->data->flag)
		printf(TEXT, MAGENT, ft_get_time() - phil->start_time, RESET, \
			phil->phil_id, MAGENT, THINK, RESET);
}

void	*start_act(void *phil_thread)
{
	t_phil_data	*phil;

	phil = (t_phil_data *)phil_thread;
	pthread_detach(phil->thread);
	while (phil->must_eat)
	{
		eating(phil);
		if (phil->must_flag && --phil->must_eat < 1)
			return (NULL);
		sleeping(phil);
		thinking(phil);
	}
	return (NULL);
}
