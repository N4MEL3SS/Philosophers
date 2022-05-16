/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:31:03 by celadia           #+#    #+#             */
/*   Updated: 2022/05/16 18:51:30 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_phil_data *phil)
{
	long		time;

	time = ft_get_time() - phil->start_time;
	sem_wait(phil->sema->forks);
	ft_msg(phil, YELLOW, FORKS, time);
	ft_msg(phil, CYAN, EAT, time);
	phil->last_meal = ft_get_time();
	ft_wait(phil->data->time_eat);
	sem_post(phil->sema->forks);
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

void	*start_bonus(t_phil_data *phil)
{
	pthread_t	dead_thread;

	pthread_create(&dead_thread, NULL, ft_check_dead, (void *)phil);
	pthread_detach(dead_thread);
	printf("id %d - %ld\n", phil->phil_id, phil->start_time);
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
