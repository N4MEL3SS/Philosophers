/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:31:03 by celadia           #+#    #+#             */
/*   Updated: 2022/05/17 17:43:51 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_msg(t_phil_data *phil, char *color, char *msg, long time)
{
	sem_wait(phil->sema->output);
	printf(TEXT, color, time, RESET, phil->phil_id, color, msg, RESET);
	sem_post(phil->sema->output);
}

void	eating(t_phil_data *phil)
{
	sem_wait(phil->sema->forks);
	ft_msg(phil, YELLOW, FORKS, ft_get_time() - phil->start_time);
	ft_msg(phil, CYAN, EAT, ft_get_time() - phil->start_time);
	phil->last_meal = ft_get_time();
	ft_wait(phil->time_eat);
	sem_post(phil->sema->forks);
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

void	*start_bonus(t_phil_data *phil)
{
	pthread_t	dead_thread;

	pthread_create(&dead_thread, NULL, thread_control, (void *)phil);
	pthread_detach(dead_thread);
	while (phil->must_eat)
	{
		eating(phil);
		if (phil->must_eat > 0)
			phil->must_eat--;
		sleeping(phil);
		thinking(phil);
	}
	exit(0);
}
