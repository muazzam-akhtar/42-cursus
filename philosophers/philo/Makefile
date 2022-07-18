# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 15:19:29 by makhtar           #+#    #+#              #
#    Updated: 2022/03/05 15:19:30 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo.a

EXEC = philo

SRCS = srcs/philo.c srcs/utils.c srcs/pars.c srcs/materials.c srcs/init.c \
		srcs/actions.c srcs/process.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -rf

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}
			${CC} ${CFLAGS} ${NAME} -o ${EXEC}

all:		${NAME}

clean:		
			${RM} ${OBJS}
			${RM} ${NAME}

fclean:		clean
			${RM} ${EXEC}
			${RM} srcs/${EXEC}

re:			fclean all