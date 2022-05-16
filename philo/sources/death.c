/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:06:45 by celadia           #+#    #+#             */
/*   Updated: 2022/05/16 17:18:08 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_wait(int delay)
{
	long	wait_time;

	wait_time = ft_get_time() + delay;
	while (ft_get_time() < wait_time)
		usleep(delay / 4);
}

int	death_checker(t_phil_data *phil)
{
	if (ft_get_time() - phil->last_meal < phil->data->time_die)
		return (0);
	pthread_mutex_lock(&phil->mutex->output);
	printf("%sThe Philosopher %d is dead. Time of death %ld %s\n", \
		RED, phil->phil_id, ft_get_time() - phil->start_time, RESET);
	phil->data->flag = 0;
	return (1);
}

void	*ft_check_dead(void *all_info)
{
	t_all	*info;
	int		i;
	int		meals;

	info = (t_all *)all_info;
	meals = 1;
	while (meals)
	{
		i = -1;
		meals = 0;
		while (++i < info->data->phil_count)
		{
			meals += info->phil[i].must_eat;
			if (death_checker(&info->phil[i]))
				return (NULL);
		}
	}
	pthread_mutex_lock(&info->mutexes->output);
	printf("%sThe Philosophers are full sad!%s\n", GREEN, RESET);
	info->data->flag = 0;
	return (NULL);
}
