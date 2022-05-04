/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:31:31 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 07:31:31 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_loop(t_all *info)
{
	int	i;
	int	j;
	int	status;

	i = -1;
	while (++i < info->data->phil_count)
	{
		waitpid(-1, &status, 0);
		if (status == 0)
		{
			j = -1;
			while (++j < info->data->phil_count)
				kill(info->phil->pid[j], SIGTERM);
		}
	}
}

void	process_init(t_all *info)
{
	int	i;

	i = -1;
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
