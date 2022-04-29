#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_all	info;

	if (argc != 5 && argc != 6)
		return (ft_error(INDEX_NUM_ARG, &info));
	if (parser(argc, argv, &info) || info.data->must_eat == 0)
		return (ft_error(INDEX_INP_ARG, &info));
	if (mutex_init(&info, info.data))
		return (ft_error(INDEX_MUTEX, &info));
	return (ft_error(phil_thread_init(&info), &info));
}
