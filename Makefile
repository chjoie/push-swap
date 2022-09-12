# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chjoie <chjoie@student.42angouleme.fr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 17:12:20 by chjoie            #+#    #+#              #
#    Updated: 2022/09/12 17:16:58 by chjoie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/push_swap.c src/parsing/check_error.c src/parsing/list_functions.c src/parsing/parsing_functions.c src/parsing/parsing_functions_2.c src/instructions/instructions_a.c src/instructions/instructions_b.c src/instructions/instructions_double.c src/instructions/instructions_double_utils.c src/sorting/sort_to_3.c src/sorting/sort_5.c src/sorting/sort_optimized.c src/utilities/utils.c src/utilities/utils_2.c src/utilities/utils_3.c

LIBFT_PATH = libft

LIBFT = libft/libft.a

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Werror -Wextra -g

RM = rm -f

CC = gcc

NAME = push_swap

all: ${NAME}

${LIBFT}:
		make -C ${LIBFT_PATH}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${OBJS} ${LIBFT} -o ${NAME}

%.o : %.c
		@${CC} ${CFLAGS} $< -c -o $@
		@echo compilating $@
clean:
		make clean -C ${LIBFT_PATH}
		${RM} ${OBJS}

fclean:	clean
		make fclean -C ${LIBFT_PATH}
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re


