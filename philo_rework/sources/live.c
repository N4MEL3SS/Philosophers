#include "../includes/philo.h"

int	ft_death(t_phil_data *phil, long time)
{
	pthread_mutex_lock(&phil->mutex->output);
	printf(TEXT, time, phil->phil_id, RED, DEATH, RESET);
	return (1);
}

int	ft_sleep(long time_to_wait, t_phil_data *phil)
{
	long		time;

	time = ft_get_time();
	time_to_wait += time;
	while (time < time_to_wait)
	{
		usleep(50);
		if (time - phil->last_meal > phil->data->time_eat)
			return (ft_death(phil, time));
		time = ft_get_time();
	}
	return (0);
}

void	eating(t_phil_data *phil)
{
	long		time;

	pthread_mutex_lock(&phil->mutex->output);
	pthread_mutex_lock(phil->r_fork);
	pthread_mutex_lock(phil->l_fork);
	phil->last_meal = ft_get_time();
	time = phil->last_meal - phil->start_time;
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
	time = ft_get_time() - phil->start_time;
	printf(TEXT, time, phil->phil_id, CYAN, SLEEP, RESET);
}

void	thinking(t_phil_data *phil)
{
	long		time;

	time = ft_get_time() - phil->start_time;
	printf(TEXT, time, phil->phil_id, MAGENTA, THINK, RESET);
}
