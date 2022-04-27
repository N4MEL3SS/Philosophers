#ifndef ERR_MSG_H
# define ERR_MSG_H

# define ERROR_NUM_ARG	"Error: Wrong number of arguments"
# define ERROR_INP_ARG	"Error: Invalid argument(-s)"
# define ERROR_MALLOC	"Error: Memory allocation error"
# define ERROR_MUTEX	"Error: Mutex(-es) couldn't be init"
# define ERROR_THREAD	"Error: Thread can't be created"
# define ERROR_THRJOIN	"Error: Thread can't be joined"

# define INDEX_NUM_ARG	2
# define INDEX_INP_ARG	3
# define INDEX_MALLOC	4
# define INDEX_MUTEX	5
# define INDEX_THREAD	6
# define INDEX_THRJOIN	7

# define TEXT	"| %ld | The Philosopher %d %s%s%s\n"

# define R_FORK "has taken a right fork"
# define L_FORK "has taken a left fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEATH	"is death"

/* Foreground colors */
# define RED 		"\e[0;31m"
# define YELLOW		"\e[0;33m"
# define GREEN 		"\e[0;32m"
# define BLUE 		"\e[0;34m"
# define MAGENTA	"\e[0;35m"
# define CYAN		"\e[0;36m"
# define RESET 	"\e[0;39m"
# define COLOR_SIZE 7

#endif //ERR_MSG_H
