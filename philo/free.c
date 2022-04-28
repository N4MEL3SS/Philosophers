#include "philo.h"

void	ft_free_forks(t_all *info)
{
	int	i;

	i = -1;
	while (++i < info->data->num_phil)
	{
		if (&info->mutexes->forks[i])
			pthread_mutex_destroy(&info->mutexes->forks[i]);
	}
	free(info->mutexes->forks);
}

void	ft_free_mutex(t_all *info)
{
	pthread_mutex_destroy(&info->mutexes->output);
	free(info->mutexes);
}

void	ft_free_all(t_all *info)
{
	if (info->phil)
		free(info->phil);
	if (info->mutexes && info->mutexes->forks)
		ft_free_forks(info);
	if (info->mutexes)
		ft_free_mutex(info);
	if (info->data)
		free(info->data);
}
