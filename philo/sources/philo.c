/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:07:00 by celadia           #+#    #+#             */
/*   Updated: 2022/05/17 13:41:55 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_all	info;

	if (argc != 5 && argc != 6)
		return (ft_error(ERRNUM_ARG_COUNT));
	if (parser(argc, argv, &data))
		return (ft_error(ERRNUM_ARG_INVAL));
	if (mutex_init(&info, &data))
		return (ft_error(info.errnum));
	if (thread_init(&info))
		return (ft_error(info.errnum));
	ft_free_all(&info, EXIT_SUCCESS);
	return (0);
}
