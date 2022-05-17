/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:06:45 by celadia           #+#    #+#             */
/*   Updated: 2022/05/17 18:15:18 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_checker(t_phil_data *phil)
{
	pthread_mutex_lock(&phil->mutex->output_block);
	if (ft_get_time() - phil->last_meal > phil->data->time_die)
	{
		printf("%sThe Philosopher %d is dead. Time of death %ld %s\n", \
			RED, phil->phil_id, ft_get_time() - phil->start_time, RESET);
		return (1);
	}
	pthread_mutex_unlock(&phil->mutex->output_block);
	return (0);
}

void	*thread_control(void *all_info)
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
			pthread_mutex_lock(&info->mutexes->data_block[i]);
			meals += info->phil[i].must_eat;
			pthread_mutex_unlock(&info->mutexes->data_block[i]);
			if (death_checker(&info->phil[i]))
				return (NULL);
		}
	}
	pthread_mutex_lock(&info->mutexes->output_block);
	printf("%sThe Philosophers are full sad!%s\n", GREEN, RESET);
	info->data->flag = 0;
	return (NULL);
}
