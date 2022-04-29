#include "../includes/philo.h"

int	ft_death(t_phil_data *phil)
{
	long	hunger_time;
	long	time;

	hunger_time = ft_get_time() - phil->stop_eat;
	time = ft_get_time() - phil->start_time;
	if (hunger_time > phil->data->time_die)
	{
		pthread_mutex_lock(&phil->mutex->output);
		printf(TEXT, time, phil->phil_id, RED, DEATH, RESET);
		return (1);
	}
	return (0);
}

void	*check_dead(void *info_data)
{
	t_all	*info;
	int		meals_count;
	int		i;

	info = (t_all *)info_data;
	meals_count = info->data->must_eat;
	usleep(500);
	while (meals_count)
	{
		i = -1;
		meals_count = 0;
		while (++i < info->data->num_phil)
		{
			meals_count += info->phil[i].must_eat;
			if (ft_death(&info->phil[i]))
				return (NULL);
			usleep(50);
		}
	}
	pthread_mutex_lock(&info->mutexes->output);
	printf("The Philosopher are full!\n");
	return (NULL);
}
