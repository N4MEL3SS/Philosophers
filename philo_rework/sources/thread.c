#include "philo.h"


void	*start_act(void *phil_thread)
{
	t_phil_data	*phil;

	phil = (t_phil_data *)phil_thread;
	pthread_detach(phil->thread);
	phil->last_meal = ft_get_time();
	while (phil->must_eat)
	{
		eating(phil);
		ft_sleep(phil->data->time_eat, phil);
		sleeping(phil);
		ft_sleep(phil->data->time_sleep, phil);
		thinking(phil);
		if (phil->must_eat > 0)
			phil->must_eat--;
	}
	return (NULL);
}

int	make_thread(t_all *info, int i)
{
	info->phil[i].start_time = ft_get_time();
	info->phil[i].last_meal = info->phil[i].start_time;
	if (pthread_create(&info->phil[i].thread, NULL, \
		&start_act, &info->phil[i]) != 0)
		return (ERRNUM_THREAD_CREATE);
	return (0);
}

int	thread_init(t_all *info)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < info->data->phil_count - 1)
	{
		error += make_thread(info, i);
		i += 2;
	}
	i = 1;
	usleep(50);
	while (i < info->data->phil_count - 1)
	{
		error += make_thread(info, i);
		i += 2;
	}
	usleep(50);
	error += make_thread(info, info->data->phil_count - 1);
	if (error)
		info->errnum = ERRNUM_THREAD_CREATE;
	return (error);
}
