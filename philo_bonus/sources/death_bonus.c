/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:30:44 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 07:30:44 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_wait(long wait_time)
{
	long	time;

	time = ft_get_time();
	wait_time += time;
	while (time < wait_time)
	{
		usleep(100);
		time = ft_get_time();
	}
}

void	death_checker(t_phil_data *phil)
{
	long	hunger_time;

	hunger_time = ft_get_time() - phil->last_meal;
	if (hunger_time > phil->data->time_die)
	{
		sem_wait(phil->sema->output);
		printf("%s| %ld | The Philosopher %d is dead |%s\n", RED, \
			ft_get_time() - phil->start_time, phil->phil_id, RESET);
		exit (0);
	}
}

void	*ft_check_dead(void *philos)
{
	t_phil_data	*phil;

	phil = (t_phil_data *)philos;
	while (phil->data->must_eat)
	{
		death_checker(phil);
		usleep(100);
	}
	sem_wait(phil->sema->output);
	printf("%sThe Philosophers are full sad!%s\n", GREEN, RESET);
	exit (0);
}
