/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:06:57 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 05:04:11 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_phil_data *phil)
{
	long		time;

	pthread_mutex_lock(phil->r_fork);
	pthread_mutex_lock(phil->l_fork);
	time = ft_get_time() - phil->start_time;
	pthread_mutex_lock(&phil->mutex->output);
	printf(TEXT, YELLOW, time, RESET, phil->phil_id, YELLOW, L_FORK, RESET);
	printf(TEXT, YELLOW, time, RESET, phil->phil_id, YELLOW, R_FORK, RESET);
	printf(TEXT, CYAN, time, RESET, phil->phil_id, CYAN, EAT, RESET);
	pthread_mutex_unlock(&phil->mutex->output);
}

void	sleeping(t_phil_data *phil)
{
	long		time;

	pthread_mutex_unlock(phil->r_fork);
	pthread_mutex_unlock(phil->l_fork);
	time = ft_get_time() - phil->start_time;
	printf(TEXT, BLUE, time, RESET, phil->phil_id, BLUE, SLEEP, RESET);
}

void	thinking(t_phil_data *phil)
{
	long		time;

	time = ft_get_time() - phil->start_time;
	printf(TEXT, MAGENTA, time, RESET, phil->phil_id, MAGENTA, THINK, RESET);
}

void	*start_act(void *phil_thread)
{
	t_phil_data	*phil;

	phil = (t_phil_data *)phil_thread;
	pthread_detach(phil->thread);
	while (phil->data->must_eat)
	{
		eating(phil);
		phil->last_meal = ft_get_time();
		ft_wait(phil->data->time_eat);
		sleeping(phil);
		ft_wait(phil->data->time_sleep);
		thinking(phil);
		if (phil->data->must_eat > 0)
			phil->data->must_eat--;
	}
	return (NULL);
}
