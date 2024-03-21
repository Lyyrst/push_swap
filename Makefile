# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 15:37:47 by kbutor-b          #+#    #+#              #
#    Updated: 2024/01/18 15:57:23 by kbutor-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADERS = push_swap.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT = src/libft/libft.a

CFILES = src/main.c \
			src/push_swap.c \
			src/check_args.c \
			src/free.c \
			src/instructions_2.c \
			src/instructions.c \
			src/set_cost.c \
			src/sort_algo.c \
			src/sort_three.c \
			src/sort_utils.c \
			src/stack_utils.c \
			src/stock_args.c \
			src/for_push.c

OFILES = $(CFILES:.c=.o)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(LIBFT) :
	$(MAKE) -C libft all

$(NAME) : $(OFILES) $(LIBFT)
	$(CC) $(OFILES) $(LIBFT) -o $(NAME)

clean :
	$(MAKE) -C libft clean
	rm -rf $(OFILES)

fclean : clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY :
	all clean fclean re
