#ifndef PHILO_H
# define PHILO_H

# include <string.h> /* memset */
# include <stdio.h> /* printf,  */
# include <stdlib.h> /* malloc, free */
# include <unistd.h> /* write, usleep, */
# include <sys/time.h> /* gettimeofday */
# include <pthread.h> /* pthread_create, pthread_detach, pthread_join,
 * pthread_mutex_init, pthread_mutex_destroy,
 * pthread_mutex_lock, pthread_mutex_unlock */

# include "message.h"

typedef struct s_data
{
	int		num_phil;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		must_eat;
	int		flag;
	long	time;
}				t_data;

typedef struct s_mutexes
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	output;
}				t_mutexes;

typedef struct s_phil_data
{
	int				phil_id;
	int				must_eat;
	long			start_time;
	long			stop_eat;
	t_data			*data;
	t_mutexes		*mutex;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}				t_phil_data;

typedef struct s_all
{
	pthread_t		death;
	t_data			*data;
	t_mutexes		*mutexes;
	t_phil_data		*phil;
}				t_all;

int		parser(int argc, char **argv, t_all *info);
int		mutex_init(t_all *info, t_data *data);
int		phil_thread_init(t_all *info);
void	*check_dead(void *all_data);

void	*start_act(void *phil_thread);

int		ft_error(int err_index, t_all *info);
void	ft_free_all(t_all *info);
long	ft_get_time(void);

#endif //PHILO_H
