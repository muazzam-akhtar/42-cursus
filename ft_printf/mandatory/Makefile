NAME	= libftprintf.a

AUTHOR = author

SRCS	= utils.c print.c ft_putnbr.c ft_printf.c

OBJS	= ${SRCS:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o : ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} : 	${OBJS} ${INCLUDE}
		ar -rcs ${NAME} ${OBJS}
		cat ${AUTHOR}


all: 		${NAME}

clean:
		${RM} ${OBJS} ${BONUS_O}


fclean: clean
			${RM} ${NAME}

re :		fclean all