/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:30:53 by celadia           #+#    #+#             */
/*   Updated: 2022/05/16 17:37:10 by celadia          ###   ########.fr       */
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
	info->data->flag = 0;
	info->phil->must_eat = info->data->must_eat;
	info->phil->data = info->data;
	info->phil->sema = info->sema;
}

void	sema_init(t_all *info, t_data *data)
{
	info->data = data;
	info->sema = (t_sema *)malloc(sizeof(t_sema));
	if (!info->sema)
		ft_error(ERROR_MALLOC_INIT);
	sem_unlink("output");
	info->sema->output = sem_open("output", O_CREAT, 0644, 1);
	if (info->sema->output == SEM_FAILED)
		ft_free_all(info, ERROR_SEMOPEN);
	sem_unlink("forks");
	info->sema->forks = sem_open("forks", O_CREAT, 0644, \
		info->data->phil_count / 2);
	if (info->sema->forks == SEM_FAILED)
		ft_free_all(info, ERROR_SEMOPEN);
	ft_init_phil(info);
}
