# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 09:39:05 by lantonio          #+#    #+#              #
#    Updated: 2024/07/25 15:57:31 by lantonio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		=  cc
FLAGS	= -Wall -Wextra -Werror -g

SRCS	= push_swap.c\
			srcs/errors.c\
			srcs/ft_split.c\
			srcs/operations_push.c\
			srcs/operations_rotate.c\
			srcs/operations_rrotate.c\
			srcs/operations_swap.c\
			srcs/sort_short.c\
			srcs/stack_init.c\
			srcs/stack_utils.c\
			srcs/stack_utils_2.c\
			srcs/stack_utils_3.c\
			srcs/stack_utils_4.c\
			srcs/stack_tests.c\
			srcs/turk_alg.c\
			srcs/utils.c\

OBJS	= $(SRCS:.c=.o)

%.c:%.0
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -Iincludes -o $(NAME)

all: $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re