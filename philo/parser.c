#include "philo.h"

int	ft_atoi(char *str, int *res)
{
	int		flag;
	long	temp;

	flag = 0;
	temp = 0;
	if (*str == '-')
		flag = 1;
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
		temp = temp * 10L + (*str++ - 48);
	if (*str != '\0' || temp > INT32_MAX || temp == 0)
		flag = 1;
	*res = (int)temp;
	return (flag);
}

int	parser(int argc, char **argv, t_all *info)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (INDEX_MALLOC);
	info->data = data;
	if (argc == 5 || argc == 6)
	{
		data->flag = 0;
		data->must_eat = -1;
		data->flag += ft_atoi(*++argv, &data->num_phil);
		data->flag += ft_atoi(*++argv, &data->time_die);
		data->flag += ft_atoi(*++argv, &data->time_eat);
		data->flag += ft_atoi(*++argv, &data->time_sleep);
		if (argc == 6)
			data->flag += ft_atoi(*++argv, &data->must_eat);
	}
	if (data->flag)
		return (INDEX_MALLOC);
	return (0);
}
