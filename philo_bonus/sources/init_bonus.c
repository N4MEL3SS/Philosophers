/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:30:53 by celadia           #+#    #+#             */
/*   Updated: 2022/05/17 17:38:53 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_phil(t_all *info)
{
	info->phil = malloc(sizeof(t_phil_data) * info->data->phil_count);
	if (!info->phil)
		ft_free_all(info, ERROR_MALLOC_INIT);
	info->phil->pid = malloc(sizeof(pid_t) * info->data->phil_count);
	if (!info->phil->pid)
		ft_free_all(info, ERROR_MALLOC_INIT);
	info->data->flag = 1;
	info->phil->must_eat = info->data->must_eat;
	info->phil->time_die = info->data->time_die;
	info->phil->time_eat = info->data->time_eat;
	info->phil->time_sleep = info->data->time_sleep;
	info->phil->sema = info->sema;
}

void	sema_init(t_all *info, t_data *data)
{
	info->data = data;
	info->sema = (t_sema *)malloc(sizeof(t_sema));
	if (!info->sema)
		ft_error(ERROR_MALLOC_INIT);
	sem_unlink("output_block");
	info->sema->output = sem_open("output_block", O_CREAT, 0644, 1);
	if (info->sema->output == SEM_FAILED)
		ft_free_all(info, ERROR_SEMOPEN);
	sem_unlink("forks");
	info->sema->forks = sem_open("forks", O_CREAT, 0644, \
		info->data->phil_count / 2);
	if (info->sema->forks == SEM_FAILED)
		ft_free_all(info, ERROR_SEMOPEN);
	ft_init_phil(info);
}

void	wait_loop(t_all *info)
{
	int	i;
	int	status;

	i = -1;
	while (++i < info->data->phil_count)
	{
		waitpid(-1, &status, 0);
		if (status == 0)
		{
			i = -1;
			while (++i < info->data->phil_count)
				kill(info->phil->pid[i], SIGTERM);
			break ;
		}
	}
}

void	process_init(t_all *info)
{
	int	i;

	i = -1;
	info->phil->start_time = ft_get_time();
	info->phil->last_meal = info->phil->start_time;
	while (++i < info->data->phil_count)
	{
		info->phil->pid[i] = fork();
		if (!info->phil->pid[i])
		{
			info->phil->phil_id = i + 1;
			start_bonus(info->phil);
		}
		else if (info->phil->pid[i] == -1)
			ft_free_all(info, ERROR_PID);
	}
	wait_loop(info);
}
