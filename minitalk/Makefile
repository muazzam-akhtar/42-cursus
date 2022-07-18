# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 14:43:50 by makhtar           #+#    #+#              #
#    Updated: 2021/12/23 16:13:14 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

AUTHOR = author

SERVER = server

CLIENT = client

SRCS = server.c client.c

OBJS = ${SRCS:.c=.o}

B_SRCS = server_bonus.c client_bonus.c

B_OBJS = ${B_SRCS:.c=.o}

LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

${NAME}: ${OBJS}
		${MAKE} all -C ./libft/
		cp ./libft/libft.a ./
		ar -rcs server.a server.o
		ar -rcs client.a client.o
		${CC} ${CFLAGS} server.a ${LIBFT} -o ${SERVER}
		${CC} ${CFLAGS} client.a ${LIBFT} -o ${CLIENT}
		cat ${AUTHOR}

all:	${NAME}

bonus:	${B_OBJS}
		${MAKE} all -C ./libft/
		cp ./libft/libft.a ./
		ar -rcs server.a server_bonus.o
		ar -rcs client.a client_bonus.o
		${CC} ${CFLAGS} server.a ${LIBFT} -o ${SERVER}
		${CC} ${CFLAGS} client.a ${LIBFT} -o ${CLIENT}
		cat ${AUTHOR}

clean:
		${MAKE} fclean -C ./libft/
		${RM} ${OBJS}
		${RM} ${B_OBJS}
		${RM} ${LIBFT}
		${RM} server.a
		${RM} client.a

fclean:	clean
		${RM} ${SERVER}
		${RM} ${CLIENT}

re:		fclean all

rebonus:	fclean bonus