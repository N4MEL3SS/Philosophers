cmake_minimum_required(VERSION 3.21)
project(philo C)

set(CMAKE_C_STANDARD 99)
#add_compile_options(-Wall -Wextra -Werror)

include_directories("philo/includes/")
#include_directories("philo_bonus/includes/")
#include_directories("philo_rework/includes/")

set(HEAD philo/includes/philo.h
		philo/includes/message.h)

set(SRC_MAN philo/sources/death.c
		philo/sources/free.c
		philo/sources/init.c
		philo/sources/live.c
		philo/sources/parser.c
		philo/sources/philo.c
		philo/sources/thread.c
		philo/sources/utils.c)

add_executable(philo_man ${SRC_MAN} ${HEAD})
target_link_libraries(philo_man pthread)

#set(HEAD_RE philo_rework/includes/philo.h
#		philo_rework/includes/message.h)
#
#set(SRC_RE philo_rework/sources/utils.c
#		philo_rework/sources/philo.c
#		philo_rework/sources/parser.c
#		philo_rework/sources/error.c
#		philo_rework/sources/init.c
#		philo_rework/sources/free.c
#		philo_rework/sources/thread.c philo_rework/sources/live.c philo_rework/sources/death.c)
#
#add_executable(philo_re ${SRC_RE} ${HEAD_RE})
#target_link_libraries(philo_re pthread)
#
#set(HEAD_BONUS philo_bonus/includes/philo_bonus.h
#		philo_bonus/includes/message_bonus.h)
#
#set(SRC_BONUS philo_bonus/source/philo_bonus.c)

#add_executable(philo_bonus ${SRC_BONUS} ${HEAD_BONUS})
#target_link_libraries(philo_bonus pthread)
