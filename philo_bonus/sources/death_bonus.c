/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:30:44 by celadia           #+#    #+#             */
/*   Updated: 2022/05/17 17:44:30 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	death_checker(t_phil_data *phil)
{
	sem_wait(phil->sema->output);
	if (ft_get_time() - phil->last_meal > phil->time_die)
	{
		printf("%sThe Philosopher %d is dead. Time of death %ld %s\n", \
			RED, phil->phil_id, ft_get_time() - phil->start_time, RESET);
		exit (0);
	}
	sem_post(phil->sema->output);
}

void	*thread_control(void *philos)
{
	t_phil_data	*phil;

	phil = (t_phil_data *)philos;
	while (phil->must_eat)
		death_checker(phil);
	sem_wait(phil->sema->output);
	printf("%sThe Philosophers are full sad!%s\n", GREEN, RESET);
	exit (0);
}
