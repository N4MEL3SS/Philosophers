cmake_minimum_required(VERSION 3.21)
project(philo C)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Wall -Wextra -Werror)

include_directories("includes/")

set(HEAD philo/philo.h
		philo/message.h)

set(SRC_MAN philo/death.c
		philo/free.c
		philo/init.c
		philo/live.c
		philo/parser.c
		philo/philo.c
		philo/thread.c
		philo/utils.c)

set(HEAD_BONUS philo_bonus/philo_bonus.h
		philo_bonus/message_bonus.h)

set(SRC_BONUS philo_bonus/philo_bonus.c)

add_executable(philo_man ${SRC_MAN} ${HEAD})
target_link_libraries(philo_man pthread)

add_executable(philo_bonus ${SRC_BONUS} ${HEAD_BONUS})
target_link_libraries(philo_bonus pthread)
