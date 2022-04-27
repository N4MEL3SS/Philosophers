#include "philo.h"

int	make_thread(t_all *info, int i)
{
	info->phil[i].stop_eat = ft_get_time();
	info->phil[i].start_time = ft_get_time();
	if (pthread_create(&info->phil[i].thread, NULL, \
		&start_act, &info->phil[i]) != 0)
		return (INDEX_THREAD);
	return (0);
}

int	thread_init(t_all *info, int f1, int f2)
{
	int	i;
	int	error;

	i = -2;
	error = 0;
	while (++i < info->data->num_phil - f1)
		error += make_thread(info, ++i);
	i = -1;
	usleep(50);
	info->data->time = ft_get_time();
	while (++i < info->data->num_phil - f2)
		error += make_thread(info, ++i);
	return (error);
}

int	phil_thread_init(t_all *info)
{
	if (thread_init(info, (info->data->num_phil - 1) % 2, \
	info->data->num_phil % 2))
		return (INDEX_THREAD);
	if (pthread_create(&info->death, NULL, &check_dead, info) != 0)
		return (INDEX_THREAD);
	if (pthread_join(info->death, NULL) != 0)
		return (INDEX_THRJOIN);
	return (0);
}
