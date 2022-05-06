/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:07:24 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 05:07:46 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	make_thread(t_all *info, int i)
{
	while (i < info->data->phil_count)
	{
		info->phil[i].start_time = info->data->start_time;
		info->phil[i].last_meal = info->phil[i].start_time;
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
	usleep(100);
	if (make_thread(info, 1))
		return (ft_free_all(info, ERRNUM_THREAD_CREATE));
	if (pthread_create(&info->dead, NULL, &ft_check_dead, info) != 0)
		return (ft_free_all(info, ERRNUM_THREAD_CREATE));
	if (pthread_join(info->dead, NULL) != 0)
		return (ft_free_all(info, ERRNUM_THREAD_JOIN));
	return (0);
}
