# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkathryn <fkathryn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 23:44:43 by fkathryn          #+#    #+#              #
#    Updated: 2020/11/16 03:16:00 by fkathryn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

INCLUDE = philo_one.h

SRCS = main.c init.c utils.c utils_libft.c condition_philo.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		@gcc $(CFLAGS) $(SRCS) -o $(NAME)

%.o: %.c $(INCLUDE)
		@gcc $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re