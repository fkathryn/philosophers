# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 20:50:00 by fkathryn          #+#    #+#              #
#    Updated: 2020/11/20 00:58:22 by fkathryn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two

INCLUDE = philo_two.h

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