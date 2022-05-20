/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:07:33 by celadia           #+#    #+#             */
/*   Updated: 2022/05/17 13:51:06 by celadia          ###   ########.fr       */
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
		info->phil[i].time_die = info->data->time_die;
		info->phil[i].time_eat = info->data->time_eat;
		info->phil[i].time_sleep = info->data->time_sleep;
		info->phil[i].must_eat = info->data->must_eat;
		info->phil[i].exit_flag = 1;
		info->phil[i].output_block = &info->mutexes->output_block;
		info->phil[i].data_block = &info->mutexes->data_block[i];
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
	info->meals = info->data->must_eat;
	info->mutexes = malloc(sizeof(t_mutexes));
	if (!info->mutexes)
		return (ft_free_all(info, ERRNUM_MALLOC_INIT));
	info->mutexes->forks = malloc(sizeof(pthread_mutex_t) * data->phil_count);
	if (!info->mutexes->forks)
		return (ft_free_all(info, ERRNUM_MALLOC_INIT));
	info->mutexes->data_block = malloc(sizeof(pthread_mutex_t) * \
			data->phil_count);
	if (!info->mutexes->data_block)
		return (ft_free_all(info, ERRNUM_MALLOC_INIT));
	if (pthread_mutex_init(&info->mutexes->output_block, NULL))
		return (ft_free_all(info, ERRNUM_MUTEX_INIT));
	while (++i < data->phil_count)
	{
		if (pthread_mutex_init(&info->mutexes->forks[i], NULL))
			return (ft_free_all(info, ERRNUM_MUTEX_INIT));
		if (pthread_mutex_init(&info->mutexes->data_block[i], NULL))
			return (ft_free_all(info, ERRNUM_MUTEX_INIT));
	}
	return (ft_init_phil(info));
}

int	make_thread(t_all *info, int i)
{
	while (i < info->data->phil_count)
	{
		info->phil[i].start_time = info->data->start_time;
		info->phil[i].last_meal = info->data->start_time;
		if (pthread_create(&info->phil[i].thread, NULL, \
			&start_act, &info->phil[i]) != 0)
			return (ERRNUM_THREAD_CREATE);
		i += 2;
	}
	return (0);
}

int	thread_init(t_all *info)
{
	info->data->start_time = ft_get_time();
	if (make_thread(info, 0))
		return (ft_free_all(info, ERRNUM_THREAD_CREATE));
	usleep(50);
	if (make_thread(info, 1))
		return (ft_free_all(info, ERRNUM_THREAD_CREATE));
	if (pthread_create(&info->dead, NULL, &thread_control, info) != 0)
		return (ft_free_all(info, ERRNUM_THREAD_CREATE));
	if (pthread_join(info->dead, NULL) != 0)
		return (ft_free_all(info, ERRNUM_THREAD_JOIN));
	return (0);
}
