NAME = a.out

SRCS = mini_serv.c

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

fclean:
	@rm -rf ${OBJS}
	@rm -rf ${NAME}

re:	fclean all