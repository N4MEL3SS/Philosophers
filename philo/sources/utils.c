/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:07:20 by celadia           #+#    #+#             */
/*   Updated: 2022/05/17 13:34:31 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_msg(t_phil_data *phil, char *color, char *msg, long time)
{
	pthread_mutex_lock(&phil->mutex->output_block);
	printf(TEXT, color, time, RESET, phil->phil_id, color, msg, RESET);
	pthread_mutex_unlock(&phil->mutex->output_block);
}

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_wait(int delay)
{
	long	wait_time;

	wait_time = ft_get_time() + delay;
	while (ft_get_time() < wait_time)
		usleep(delay / 4);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str && ++len)
		str++;
	return (len);
}
