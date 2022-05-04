/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:06:52 by celadia           #+#    #+#             */
/*   Updated: 2022/05/04 03:00:05 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

# define ERRNUM_ARG_COUNT		2
# define ERRNUM_ARG_INVAL		3
# define ERRNUM_MALLOC_INIT		4
# define ERRNUM_MUTEX_INIT		5
# define ERRNUM_THREAD_CREATE	6
# define ERRNUM_THREAD_JOIN		7

# define ERROR_ARG_COUNT		"Wrong number of arguments"
# define ERROR_ARG_INVAL		"Invalid argument(-s)"
# define ERROR_MALLOC_INIT		"Memory allocation error"
# define ERROR_MUTEX_INIT		"Mutex(-es) couldn't be init"
# define ERROR_THREAD_CREATE	"Thread can't be created"
# define ERROR_THREAD_JOIN		"Thread can't be joined"

# define TEXT	"| %s%ld%s | The Philosopher %d %s%s%s |\n"
# define L_FORK 	"has taken a left fork"
# define R_FORK 	"has taken a right fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEATH	"died"

/* Foreground colors */
# define RED 		"\e[0;31m"
# define GREEN 		"\e[3;32m"
# define GREY 		"\e[3;37m"
# define YELLOW		"\e[0;33m"
# define BLUE 		"\e[0;34m"
# define MAGENTA	"\e[0;35m"
# define CYAN		"\e[0;36m"
# define RESET 		"\e[0;39m"

# define COLOR_SIZE	7

#endif //MESSAGE_H
