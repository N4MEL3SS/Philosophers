/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:07:29 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 04:45:38 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str, int *res)
{
	unsigned long	temp;

	temp = 0;
	if (*str == '-')
		return (1);
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
		temp = temp * 10L + (*str++ - 48);
	if (*str != '\0' || temp > INT32_MAX)
		return (1);
	*res = (int)temp;
	return (0);
}

int	parser(int argc, char **argv, t_data *data)
{
	data->flag = 0;
	data->flag += ft_atoi(argv[1], &data->phil_count);
	data->flag += ft_atoi(argv[2], &data->time_die);
	data->flag += ft_atoi(argv[3], &data->time_eat);
	data->flag += ft_atoi(argv[4], &data->time_sleep);
	if (argc == 6)
		data->flag += ft_atoi(argv[5], &data->must_eat);
	else
		data->must_eat = -1;
	if (!data->phil_count)
		return (ft_forever());
	return (data->flag);
}
