/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:30:35 by celadia           #+#    #+#             */
/*   Updated: 2022/05/16 17:07:34 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h> /* memset */
# include <stdio.h> /* printf,  */
# include <stdlib.h> /* malloc, free, exit */
# include <unistd.h> /* write, usleep, fork */
# include <sys/time.h> /* gettimeofday */
# include <pthread.h> /* pthread_create, pthread_detach, pthread_join,
 * pthread_mutex_init, pthread_mutex_destroy,
 * pthread_mutex_lock, pthread_mutex_unlock */

# include <limits.h>
# include <sys/types.h> /* waitpid */
# include <signal.h> /* kill */
# include <semaphore.h> /* sem_open, sem_close, sem_post,
 * sem_wait, sem_unlink */

# include "message_bonus.h"

typedef struct s_data
{
	int		phil_count;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		must_eat;
	int		flag;
}				t_data;

typedef struct s_sema
{
	sem_t	*forks;
	sem_t	*output;
}				t_sema;

typedef struct s_phil_data
{
	int			phil_id;
	int			must_eat;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	long		start_time;
	long		last_meal;
	pid_t		*pid;
	t_sema		*sema;
}				t_phil_data;

typedef struct s_all
{
	t_data			*data;
	t_sema			*sema;
	t_phil_data		*phil;
}				t_all;

int		parser(int argc, char **argv, t_data *data);
void	sema_init(t_all *info, t_data *data);
void	process_init(t_all *info);
void	*start_bonus(t_phil_data *phil);

void	ft_error(char *str);
void	ft_free_all(t_all *info, char *str);
void	ft_forever(void);

void	ft_wait(int delay);
void	*thread_control(void *philos);

/* utils.c */
int		ft_strlen(const char *str);
long	ft_get_time(void);

#endif //PHILO_BONUS_H
