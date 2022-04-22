#include "philo.h"

int	ft_atoi(char *str, long *res)
{
	int		flag;

	flag = 0;
	*res = 0;
	if (*str == '-')
		flag = 1;
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
		*res = *res * 10L + (*str++ - 48);
	if (*str != '\0')
		flag = 1;
	if (*res > INT32_MAX)
		flag = 1;
	return (flag);
}

t_data	*parser(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)mem_alloc(sizeof(t_data));
	data->flag = 0;
	data->must_eat = 0;
	if (argc == 5 || argc == 6)
	{
		data->flag += ft_atoi(*++argv, &data->num_phil);
		data->flag += ft_atoi(*++argv, &data->time_die);
		data->flag += ft_atoi(*++argv, &data->time_eat);
		data->flag += ft_atoi(*++argv, &data->time_sleep);
		if (argc == 6)
			data->flag += ft_atoi(*++argv, &data->must_eat);
	}
	return (data);
}
