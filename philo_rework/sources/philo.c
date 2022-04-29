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
	return (0);
}
