/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:31:03 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 07:31:03 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_phil_data *phil)
{
	long		time;

	sem_wait(phil->sema->forks);
	time = ft_get_time() - phil->start_time;
	sem_wait(phil->sema->output);
	printf(TEXT, YELLOW, time, RESET, phil->phil_id, YELLOW, L_FORK, RESET);
	printf(TEXT, YELLOW, time, RESET, phil->phil_id, YELLOW, R_FORK, RESET);
	printf(TEXT, CYAN, time, RESET, phil->phil_id, CYAN, EAT, RESET);
	sem_post(phil->sema->output);
	phil->last_meal = ft_get_time();
	ft_wait(phil->data->time_eat);
	sem_post(phil->sema->forks);
}

void	sleeping(t_phil_data *phil)
{
	long		time;

	time = ft_get_time() - phil->start_time;
	printf(TEXT, BLUE, time, RESET, phil->phil_id, BLUE, SLEEP, RESET);
	ft_wait(phil->data->time_sleep);
}

void	thinking(t_phil_data *phil)
{
	long		time;

	time = ft_get_time() - phil->start_time;
	printf(TEXT, MAGENTA, time, RESET, phil->phil_id, MAGENTA, THINK, RESET);
}

void	*start_bonus(t_phil_data *phil)
{
	pthread_t	dead_flag;

	phil->start_time = ft_get_time();
	phil->last_meal = ft_get_time();
	pthread_create(&dead_flag, NULL, ft_check_dead, (void *)phil);
	pthread_detach(dead_flag);
	while (phil->data->must_eat)
	{
		eating(phil);
		if (phil->data->must_eat > 0)
			phil->data->must_eat--;
		sleeping(phil);
		thinking(phil);
	}
	exit(0);
}
