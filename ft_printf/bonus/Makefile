# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 11:49:30 by makhtar           #+#    #+#              #
#    Updated: 2021/11/04 11:49:30 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

AUTHOR = author

SRCS	= utils.c print.c flags_f.c ft_printf.c \
			parse.c print_un.c utils1.c utils2.c \
			work_int.c work_un.c

OBJS	= ${SRCS:.c=.o}

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

.c.o : ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} : 	${OBJS}
		ar -rcs ${NAME} ${OBJS}
		cat ${AUTHOR}


all: 		${NAME}

bonus:		${OBJS}
		ar -rcs ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re :		fclean all

rebonus:	fclean bonus