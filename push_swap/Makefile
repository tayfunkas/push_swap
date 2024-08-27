# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkasapog <tkasapog@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 12:30:06 by tkasapog          #+#    #+#              #
#    Updated: 2024/07/02 12:33:51 by tkasapog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror


SRCS= push_commands.c \
	reverse_rotate_commands.c \
	rotate_commands.c \
	sorting_helpers.c \
	index_range.c \
	sort_small_stacks.c \
	stack_init.c \
	swap_commands.c \
	condition_checks.c \
	sort_large.c \
	main.c \
	ft_split.c \
	ft_strchr.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
