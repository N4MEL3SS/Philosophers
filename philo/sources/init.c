#include "../includes/philo.h"

int	ft_init_phil(t_all *info)
{
	int	i;

	i = -1;
	info->phil = malloc(sizeof(t_phil_data) * info->data->num_phil);
	if (!info->phil)
		return (INDEX_MALLOC);
	while (++i < info->data->num_phil)
	{
		info->phil[i].phil_id = i + 1;
		info->phil[i].must_eat = info->data->must_eat;
		info->phil[i].data = info->data;
		info->phil[i].mutex = info->mutexes;
		info->phil[i].r_fork = &info->mutexes->forks[i];
		info->phil[i].l_fork = &info->mutexes->forks[(i + 1) % \
			info->data->num_phil];
	}
	return (0);
}

int	mutex_init(t_all *info, t_data *data)
{
	int			i;

	i = -1;
	info->data = data;
	info->mutexes = malloc(sizeof(t_mutexes));
	if (!info->mutexes)
		return (INDEX_MALLOC);
	info->mutexes->forks = malloc(sizeof(pthread_mutex_t) * data->num_phil);
	if (!info->mutexes->forks)
		return (INDEX_MALLOC);
	if (pthread_mutex_init(&info->mutexes->output, NULL))
		return (INDEX_MUTEX);
	while (++i < data->num_phil)
	{
		if (pthread_mutex_init(&info->mutexes->forks[i], NULL))
			return (INDEX_MUTEX);
	}
	return (ft_init_phil(info));
}
