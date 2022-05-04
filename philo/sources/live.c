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
	time = ft_get_time() - phil->start_time;
	if (phil->data->flag)
	{
		pthread_mutex_lock(&phil->mutex->output);
		printf(TEXT, YELLOW, time, RESET, phil->phil_id, YELLOW, L_FORK, RESET);
		printf(TEXT, YELLOW, time, RESET, phil->phil_id, YELLOW, R_FORK, RESET);
		printf(TEXT, CYAN, time, RESET, phil->phil_id, CYAN, EAT, RESET);
		pthread_mutex_unlock(&phil->mutex->output);
	}
	phil->last_meal = ft_get_time();
	ft_wait(phil->data->time_eat);
}

void	sleeping(t_phil_data *phil)
{
	long		time;

	pthread_mutex_unlock(phil->r_fork);
	pthread_mutex_unlock(phil->l_fork);
	if (phil->data->flag)
	{
		time = ft_get_time() - phil->start_time;
		printf(TEXT, BLUE, time, RESET, phil->phil_id, BLUE, SLEEP, RESET);
	}
	ft_wait(phil->data->time_sleep);
}

void	thinking(t_phil_data *phil)
{
	long		time;

	if (phil->data->flag)
	{
		time = ft_get_time() - phil->start_time;
		printf(TEXT, MAGENT, time, RESET, phil->phil_id, MAGENT, THINK, RESET);
	}
}

void	*start_act(void *phil_thread)
{
	t_phil_data	*phil;

	phil = (t_phil_data *)phil_thread;
	pthread_detach(phil->thread);
	while (1)
	{
		if (phil->must_eat != 0)
		{
			eating(phil);
			if (phil->must_eat > 0)
				phil->must_eat--;
			sleeping(phil);
			thinking(phil);
		}
	}
	return (NULL);
}
