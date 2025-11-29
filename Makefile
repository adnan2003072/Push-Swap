# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 12:07:52 by abouzkra          #+#    #+#              #
#    Updated: 2025/11/29 09:29:24 by abouzkra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
MSRCS = srcs/ft_atoi.c srcs/ft_isdigit.c srcs/ft_newnode.c srcs/ft_addnode_front.c \
		srcs/ft_clearlst.c \
		stack_utils/init_stack.c stack_utils/swap_a.c stack_utils/swap_b.c stack_utils/swap_s.c stack_utils/pop.c \
		stack_utils/push_a.c stack_utils/push_b.c stack_utils/rotate_a.c stack_utils/rotate_b.c stack_utils/rotate_r.c \
		srcs/main.c
MOBJS = $(MSRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(MOBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(MOBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(MOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
