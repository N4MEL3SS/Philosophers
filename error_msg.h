#ifndef ERR_MSG_H
# define ERR_MSG_H

# define ERR_NUM_ARG	"Error: wrong number of arguments"
# define ERR_INP_ARG	"Error: invalid argument(-s)"
# define ERR_MALLOC		"Error: memory allocation error"
# define ERR_MUTEX		"Error: mutex(-es) couldn't be init"
# define ERR_THREAD		"Error: thread can't be created"
# define ERR_THRJOIN	"Error: thread can't be joined"

/* Foreground colors */
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define BLUE "\e[0;34m"
# define COLOR_END "\e[0;39m"
# define COLOR_SIZE 7

#endif //ERR_MSG_H
