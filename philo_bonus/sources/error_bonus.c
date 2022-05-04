/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:30:48 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 07:30:48 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_error(char *str)
{
	if (*str == '\0')
		exit(EXIT_SUCCESS);
	write(2, RED, COLOR_SIZE);
	write(2, "Error: ", 7);
	write(2, GREEN, COLOR_SIZE);
	write(2, str, ft_strlen(str));
	write(2, RESET, COLOR_SIZE);
	exit(EXIT_FAILURE);
}

void	ft_forever(void)
{
	write(2, GREY, COLOR_SIZE);
	write(2, "We're here, it's now\n", 21);
	write(2, "We live forever\n", 16);
	write(2, "The time has come\n", 18);
	write(2, "We live forever\n", 16);
	write(2, RESET, COLOR_SIZE);
	ft_error(ERROR_ARG_INVAL);
}

void	ft_free_all(t_all *info, char *str)
{
	sem_unlink("output");
	sem_unlink("forks");
	if (info->sema->output)
		sem_close(info->sema->output);
	if (info->sema->forks)
		sem_close(info->sema->forks);
	ft_error(str);
}
