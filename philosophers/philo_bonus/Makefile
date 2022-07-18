# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 15:19:58 by makhtar           #+#    #+#              #
#    Updated: 2022/03/05 15:19:59 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo.a

EXEC = philo

SRCS = srcs/utils.c srcs/philo_bonus.c srcs/resources.c srcs/parse.c \
		srcs/init.c srcs/actions.c

RM = rm -rf

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

TFLAGS = -pthread

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}
			${CC} ${CFLAGS} ${TFLAGS} ${NAME} -o ${EXEC}

all:		${NAME}

clean:
		${RM} ${OBJS}
		${RM} ${NAME}

fclean:	clean
		${RM} ${EXEC}

re:		fclean all