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
	pthread_mutex_lock(phil->output_block);
	printf(TEXT, color, time, RESET, phil->phil_id, color, msg, RESET);
	pthread_mutex_unlock(phil->output_block);
}

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_wait(t_phil_data *phil, int delay, int flag)
{
	long	time;

	time = ft_get_time();
	pthread_mutex_lock(phil->data_block);
	phil->last_meal = time;
	pthread_mutex_unlock(phil->data_block);
	if (flag)
	{
		ft_msg(phil, YELLOW, L_FORK, time - phil->start_time);
		ft_msg(phil, YELLOW, R_FORK, time - phil->start_time);
		ft_msg(phil, CYAN, EAT, time - phil->start_time);
	}
	else
		ft_msg(phil, BLUE, SLEEP, time - phil->start_time);
	time += delay;
	while (ft_get_time() < time)
		usleep(delay / 8);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str && ++len)
		str++;
	return (len);
}
