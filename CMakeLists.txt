cmake_minimum_required(VERSION 3.21)
project(philo C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -Werror)
include_directories("philo/includes/")

set(HEAD philo/includes/message.h
		philo/includes/philo.h)

set(SRC philo/sources/philo.c
		philo/sources/parser.c
		philo/sources/error.c
		philo/sources/init.c
		philo/sources/thread.c
		philo/sources/free.c
		philo/sources/utils.c
		philo/sources/live.c
		philo/sources/death.c)

add_executable(philo ${SRC} ${HEAD})
