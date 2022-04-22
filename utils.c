#include "philo.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str && ++len)
		str++;
	return (len);
}

void	ft_message(const char *str, char *color)
{
	write(1, color, COLOR_SIZE);
	write(1, str, ft_strlen(str));
	write(1, COLOR_END, COLOR_SIZE);
	write(1, "\n", 1);
}

void	*mem_alloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_message(ERR_MALLOC, RED);
	return (ptr);
}
