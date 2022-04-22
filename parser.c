#include "philo.h"

int	ft_atoi(char *str, long *res)
{
	if (*str == '-')
		return (1);
	else if (*str == '+')
		str++;
	while ('0' <= *str && *str <= '9')
		*res = *res * 10L + (long)*str++ - 48L;
	if (*str != '\0')
		return (1);
	if (*res > INT32_MAX)
		return (1);
	return (0);
}

t_data	*parser(int argc, char **argv)
{
	t_data	*data;
	long	temp;

	temp = 0;
	data = (t_data *)malloc(sizeof(t_data));
	if (argc == 5 || argc == 6)
	{
		while (--argc)
		{
			if (ft_atoi(*argv, &temp))
				return (ERR_INP_ARG);
		}
	}
	return (data);
}