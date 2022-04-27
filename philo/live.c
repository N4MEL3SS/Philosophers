#include "philo.h"

void	ft_sleep(long time_to_wait)
{
	long		time;

	time = ft_get_time();
	time_to_wait += time;
	while (time < time_to_wait)
	{
		usleep(50);
		time = ft_get_time();
	}
}

void	eating(t_phil_data *phil)
{
	long		time;

	pthread_mutex_lock(&phil->mutex->output);
	pthread_mutex_lock(phil->r_fork);
	pthread_mutex_lock(phil->l_fork);
	time = ft_get_time() - phil->start_time;
	printf(TEXT, time, phil->phil_id, YELLOW, R_FORK, RESET);
	printf(TEXT, time, phil->phil_id, YELLOW, L_FORK, RESET);
	printf(TEXT, time, phil->phil_id, BLUE, EAT, RESET);
	pthread_mutex_unlock(&phil->mutex->output);
}

void	sleeping(t_phil_data *phil)
{
	long		time;

	pthread_mutex_unlock(phil->r_fork);
	pthread_mutex_unlock(phil->l_fork);
	phil->stop_eat = ft_get_time();
	time = phil->stop_eat - phil->start_time;
	printf(TEXT, time, phil->phil_id, CYAN, SLEEP, RESET);
}

void	thinking(t_phil_data *phil)
{
	long		time;

	time = ft_get_time() - phil->start_time;
	printf(TEXT, time, phil->phil_id, MAGENTA, THINK, RESET);
}

void	*start_act(void *phil_thread)
{
	t_phil_data	*phil;

	phil = (t_phil_data *)phil_thread;
	phil->stop_eat = ft_get_time();
	pthread_detach(phil->thread);
	while (phil->must_eat)
	{
		eating(phil);
		ft_sleep(phil->data->time_eat);
		sleeping(phil);
		ft_sleep(phil->data->time_sleep);
		thinking(phil);
		if (phil->must_eat > 0)
			phil->must_eat--;
	}
	return (NULL);
}
