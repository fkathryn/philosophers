# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 23:44:43 by fkathryn          #+#    #+#              #
#    Updated: 2020/11/19 20:40:08 by fkathryn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

INCLUDE = philo_one.h

SRCS = srcs/main.c srcs/init.c srcs/utils.c srcs/utils_libft.c \
		 srcs/condition_philo.c srcs/check_param.c 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		@clang $(CFLAGS) $(SRCS) -o $(NAME)

%.o: %.c $(INCLUDE)
		@clang $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re