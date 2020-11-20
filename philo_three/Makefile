# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 02:56:19 by fkathryn          #+#    #+#              #
#    Updated: 2020/11/20 02:56:37 by fkathryn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

INCLUDE = philo_three.h

SRCS = srcs/main.c srcs/utils.c srcs/libft_utils.c  \
		srcs/init.c srcs/condition_philo.c srcs/check_param.c

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