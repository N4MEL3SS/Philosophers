# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: celadia <celadia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 07:29:28 by celadia           #+#    #+#              #
#    Updated: 2022/05/17 13:54:44 by celadia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	PROGRAM_NAMES
NAME = philo
NAME_DEBUG = philo_debug

#	FLAG_COMPILATION
CC = clang
FLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -Wall -Werror -Wextra -fsanitize=thread
HEADERS_DIR = ./includes/
INCLUDES = -I$(HEADERS_DIR)

#	HEADERS
HEADERS_LIST = 	message.h	\
				philo.h
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

#	SOURCE
SRCS_DIR = ./sources/
SRCS_LIST = death.c			\
			error.c			\
			free.c			\
			init.c			\
			live.c			\
			parser.c		\
			philo.c			\
			utils.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

#	OBJECT_FILES
OBJS_DIR = ./objs/
OBJS_DIR_NAME = objs
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_LIST))

#	COLORS
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(GREEN) $(NAME) created. $(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR_NAME)
	@echo "$(GREEN) Object files directory was created. $(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "$(RED) Object files were deleted. $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_DEBUG)
	@echo "$(RED) $(NAME) was deleted. $(RESET)"
	@rm -rf $(OBJS_DIR_NAME)

debug: fclean $(OBJS_DIR) $(OBJS)
	@echo "$(GREEN) Debug mod: $(RESET)"
	@$(CC) $(DEBUG_FLAGS) $(INCLUDES) $(OBJS) -o $(NAME_DEBUG)
	@echo "$(GREEN) $(NAME_DEBUG) created. $(RESET)"

re: fclean all

.PHONY: all clean fclean debug re
