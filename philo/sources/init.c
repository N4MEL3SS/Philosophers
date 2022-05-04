/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:07:33 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 12:02:00 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_phil(t_all *info)
{
	int	i;

	i = -1;
	info->phil = malloc(sizeof(t_phil_data) * info->data->phil_count);
	if (!info->phil)
		return (ft_free_all(info, ERRNUM_MALLOC_INIT));
	while (++i < info->data->phil_count)
	{
		info->phil[i].phil_id = i + 1;
		info->phil[i].data = info->data;
		info->phil[i].must_eat = info->data->must_eat;
		info->phil[i].mutex = info->mutexes;
		info->phil[i].r_fork = &info->mutexes->forks[i];
		info->phil[i].l_fork = &info->mutexes->forks[(i + 1) % \
			info->data->phil_count];
	}
	return (0);
}

int	mutex_init(t_all *info, t_data *data)
{
	int			i;

	i = -1;
	info->data = data;
	info->data->flag = 1;
	info->mutexes = malloc(sizeof(t_mutexes));
	if (!info->mutexes)
		return (ft_free_all(info, ERRNUM_MALLOC_INIT));
	info->mutexes->forks = malloc(sizeof(pthread_mutex_t) * data->phil_count);
	if (!info->mutexes->forks)
		return (ft_free_all(info, ERRNUM_MALLOC_INIT));
	if (pthread_mutex_init(&info->mutexes->output, NULL))
		return (ft_free_all(info, ERRNUM_MUTEX_INIT));
	while (++i < data->phil_count)
	{
		if (pthread_mutex_init(&info->mutexes->forks[i], NULL))
			return (ft_free_all(info, ERRNUM_MUTEX_INIT));
	}
	return (ft_init_phil(info));
}
