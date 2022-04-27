#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str && ++len)
		str++;
	return (len);
}

int	ft_error(int err_index, t_all *info)
{
	ft_free_all(info);
	if (err_index == 0)
		return (EXIT_SUCCESS);
	write(2, RED, COLOR_SIZE);
	if (err_index == INDEX_NUM_ARG)
		write(2, ERROR_NUM_ARG, ft_strlen(ERROR_NUM_ARG));
	else if (err_index == INDEX_INP_ARG)
		write(2, ERROR_INP_ARG, ft_strlen(ERROR_INP_ARG));
	else if (err_index == INDEX_MALLOC)
		write(2, ERROR_MALLOC, ft_strlen(ERROR_MALLOC));
	else if (err_index == INDEX_MUTEX)
		write(2, ERROR_MUTEX, ft_strlen(ERROR_MUTEX));
	else if (err_index == INDEX_THREAD)
		write(2, ERROR_THREAD, ft_strlen(ERROR_THREAD));
	else if (err_index == INDEX_THRJOIN)
		write(2, ERROR_THRJOIN, ft_strlen(ERROR_THRJOIN));
	write(2, RESET, COLOR_SIZE);
	write(2, "\n", 1);
	return (EXIT_FAILURE);
}
