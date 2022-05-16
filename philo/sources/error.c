/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:07:45 by celadia           #+#    #+#             */
/*   Updated: 2022/05/16 16:08:33 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_forever(void)
{
	write(1, GREY, COLOR_SIZE);
	write(1, "We're here, it's now\n", 21);
	write(1, "We live forever\n", 16);
	write(1, "The time has come\n", 18);
	write(1, "We live forever\n", 16);
	write(1, RESET, COLOR_SIZE);
	return (EXIT_FAILURE);
}

int	ft_error(int errnum)
{
	write(2, RED, COLOR_SIZE);
	write(2, "Error: ", 7);
	write(2, GREEN, COLOR_SIZE);
	if (errnum == ERRNUM_ARG_COUNT)
		write(2, ERROR_ARG_COUNT, ft_strlen(ERROR_ARG_COUNT));
	else if (errnum == ERRNUM_ARG_INVAL)
		write(2, ERROR_ARG_INVAL, ft_strlen(ERROR_ARG_INVAL));
	else if (errnum == ERRNUM_MALLOC_INIT)
		write(2, ERROR_MALLOC_INIT, ft_strlen(ERROR_MALLOC_INIT));
	else if (errnum == ERRNUM_MUTEX_INIT)
		write(2, ERROR_MUTEX_INIT, ft_strlen(ERROR_MUTEX_INIT));
	else if (errnum == ERRNUM_THREAD_CREATE)
		write(2, ERROR_THREAD_CREATE, ft_strlen(ERROR_THREAD_CREATE));
	else if (errnum == ERRNUM_THREAD_JOIN)
		write(2, ERROR_THREAD_JOIN, ft_strlen(ERROR_THREAD_JOIN));
	write(2, RESET, COLOR_SIZE);
	write(2, "\n", 1);
	return (EXIT_FAILURE);
}
