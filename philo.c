#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (terminate(ERR_NUM_ARG, RED, NULL));
	data = parser(argc, argv);
	if (data->flag)
		return (terminate(ERR_INP_ARG, RED, data));
	return (0);
}
