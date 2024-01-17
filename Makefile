# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbutor-b <kbutor-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 15:37:47 by kbutor-b          #+#    #+#              #
#    Updated: 2024/01/17 16:08:35 by kbutor-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADERS = push_swap.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT = libft/libft.a

CFILES = main.c \
			push_swap.c \
			check_args.c \
			free.c \
			instructions_2.c \
			instructions.c \
			set_cost.c \
			sort_algo.c \
			sort_three.c \
			sort_utils.c \
			stack_utils.c \
			stock_args.c

OFILES = $(CFILES:.c = .o)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(LIBFT) :
	$(MAKE) -C libft all

$(NAME) : $(OFILES) $(LIBFT)
	$(CC) $(OFILES) $(LIBFT) -o $(NAME)

clean :
	$(MAKE) -C libft clean
	rm -rf $(OFILES)

fclean : clean
	$(MAKE) -C libft flcean
	rm -rf $(NAME)

re : fclean $(NAME)

all : $(NAME)

.PHONY :
	all clean fclean re