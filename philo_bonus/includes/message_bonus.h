/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:30:28 by celadia           #+#    #+#             */
/*   Updated: 2022/05/16 18:07:55 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_BONUS_H
# define MESSAGE_BONUS_H

# define ERROR_ARG_COUNT		"Wrong number of arguments\n"
# define ERROR_ARG_INVAL		"Invalid argument(-s)\n"
# define ERROR_MALLOC_INIT		"Memory allocation error"
# define ERROR_SEMOPEN			"Failed to open semaphore\n"
# define ERROR_PID				"Failed to create process\n"

# define TEXT		"| %s%ld%s | The Philosopher %d %s%s%s |\n"
# define FORKS	 	"has taken the forks"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"

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

#endif //MESSAGE_BONUS_H
