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

# include "error_msg.h"

typedef struct s_data
{
	long	num_phil;
	long	time_die;
	long	time_eat;
	long	time_sleep;
	long	must_eat;
	int		flag;
}				t_data;

t_data	*parser(int argc, char **argv);
void	ft_message(const char *str, char *color);
int		terminate(const char *str, char *color, void *ptr);
void	*mem_alloc(size_t size);

#endif //PHILO_H
