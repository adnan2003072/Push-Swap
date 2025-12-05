# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 12:07:52 by abouzkra          #+#    #+#              #
#    Updated: 2025/12/05 12:04:51 by abouzkra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Iincludes
MSRCS = utils/ft_atoi.c          \
		utils/ft_strlen.c        \
		utils/ft_strdup.c        \
		utils/ft_substr.c        \
		utils/ft_split.c         \
		utils/free_split.c       \
		utils/ft_isdigit.c       \
		utils/ft_newnode.c       \
		utils/ft_addnode_front.c \
		utils/ft_clearlst.c      \
		utils/init_stack.c 		 \
		utils/push.c		 	 \
		utils/swap.c 			 \
		utils/rotate.c 		     \
		utils/rev_rotate.c       \
		utils/pop.c 		     \
		srcs/parsing.c           \
		srcs/sort_utils.c		 \
		srcs/median.c			 \
		srcs/cost.c				 \
		srcs/sort.c				 \
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
