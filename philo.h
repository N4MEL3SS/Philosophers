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
	int		num_phil;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		must_eat;
}				t_data;

#endif //PHILO_H
