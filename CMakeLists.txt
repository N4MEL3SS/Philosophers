cmake_minimum_required(VERSION 3.20)
project(philo C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -Werror)

include_directories("philo/includes/")
set(HEAD philo/includes/message.h
		philo/includes/philo.h)

set(SRC philo/sources/death.c
		philo/sources/error.c
		philo/sources/free.c
		philo/sources/init.c
		philo/sources/live.c
		philo/sources/parser.c
		philo/sources/philo.c
		philo/sources/utils.c)

add_executable(philo ${SRC} ${HEAD})

include_directories("philo_bonus/includes/")
set(HEAD_BONUS philo_bonus/includes/message_bonus.h
		philo_bonus/includes/philo_bonus.h)

set(SRC_BONUS philo_bonus/sources/death_bonus.c
		philo_bonus/sources/error_bonus.c
		philo_bonus/sources/init_bonus.c
		philo_bonus/sources/live_bonus.c
		philo_bonus/sources/parser_bonus.c
		philo_bonus/sources/philo_bonus.c
		philo_bonus/sources/utils_bonus.c)

add_executable(philo_bonus ${SRC_BONUS} ${HEAD_BONUS})
