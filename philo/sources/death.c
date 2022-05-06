/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:06:45 by celadia           #+#    #+#             */
/*   Updated: 2022/05/06 19:35:44 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	death_checker(t_phil_data *phil)
{
	long	hunger_time;

	hunger_time = ft_get_time() - phil->last_meal;
	if (hunger_time > phil->data->time_die)
	{
		pthread_mutex_lock(&phil->mutex->output);
		printf("%sThe Philosopher %d is dead. Time of death %ld %s\n", \
			RED, phil->phil_id, ft_get_time() - phil->start_time, RESET);
		return (1);
	}
	return (0);
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
			if (death_checker(&info->phil[i]))
				return (NULL);
			meals += info->phil[i].must_eat;
		}
		if (meals == 0)
			info->data->flag = 0;
	}
	pthread_mutex_lock(&info->mutexes->output);
	printf("%sThe Philosophers are full sad!%s\n", GREEN, RESET);
	return (NULL);
}
