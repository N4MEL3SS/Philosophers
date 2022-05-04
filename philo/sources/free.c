/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:07:38 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 04:57:14 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_free_forks(t_all *info)
{
	int	i;

	i = -1;
	while (++i < info->data->phil_count)
	{
		if (&info->mutexes->forks[i])
			pthread_mutex_destroy(&info->mutexes->forks[i]);
	}
	free(info->mutexes->forks);
}

void	ft_free_mutex(t_all *info)
{
	pthread_mutex_unlock(&info->mutexes->output);
	pthread_mutex_destroy(&info->mutexes->output);
	free(info->mutexes);
}

int	ft_free_all(t_all *info, int errnum)
{
	if (info->phil)
		free(info->phil);
	if (info->mutexes && info->mutexes->forks)
		ft_free_forks(info);
	if (info->mutexes)
		ft_free_mutex(info);
	info->errnum = errnum;
	return (errnum);
}
