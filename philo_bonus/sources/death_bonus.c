/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:30:44 by celadia           #+#    #+#             */
/*   Updated: 2022/05/16 18:41:09 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_wait(int delay)
{
	long	wait_time;

	wait_time = ft_get_time() + delay;
	while (ft_get_time() < wait_time)
		usleep(delay / 4);
}

void	death_checker(t_phil_data *phil)
{
	if (ft_get_time() - phil->last_meal > phil->data->time_die)
	{
		sem_wait(phil->sema->output);
		printf("%sThe Philosopher %d is dead. Time of death %ld %s\n", \
			RED, phil->phil_id, ft_get_time() - phil->start_time, RESET);
		phil->data->flag = 1;
		exit (0);
	}
}

void	*ft_check_dead(void *philos)
{
	t_phil_data	*phil;
	int			delay;
	int			meals;

	meals = 0;
	phil = (t_phil_data *)philos;
	delay = phil->data->time_die / 4;
	while (phil->must_eat)
	{
		death_checker(phil);
		meals += phil->must_eat;
		if (meals == 0)
		{
			sem_wait(phil->sema->output);
			printf("%sThe Philosophers are full sad!%s\n", GREEN, RESET);
			exit (0);
		}
	}
	exit (0);
}
