cmake_minimum_required(VERSION 3.21)
project(philo C)

set(CMAKE_C_STANDARD 99)

include_directories("includes/")

set(HEAD philo.h
		error_msg.h)

set(SRC_MAN philo.c
		utils.c parser.c)

add_executable(philo_man ${SRC_MAN} ${HEAD})
target_link_libraries(philo_man pthread)
