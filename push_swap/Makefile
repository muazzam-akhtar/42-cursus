# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:26:27 by makhtar           #+#    #+#              #
#    Updated: 2022/01/24 17:26:27 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

RES = push_swap

CHECKER = checker

AUTHOR = author.txt

LIBFT = libft.a

SRCS = push_swap.c small_sort.c operations.c utils.c resources.c init.c \
		allocate.c five_sort.c big_sort.c reverse_rot_operations.c \
		rotations.c look_num.c look_index.c rot_operations.c sort.c \

C_SRCS = checker.c allocate.c init.c do_op.c resources.c utils.c get_next_line.c \
			get_next_line_utils.c operations.c rot_operations.c  \
			reverse_rot_operations.c \

OBJS = ${SRCS:.c=.o}

C_OBJS = ${C_SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

${NAME}:	${OBJS}
			${MAKE} -C ./libft
			cp ./libft/libft.a ./
			ar -rcs ${NAME} ${OBJS}
			${CC} ${NAME} ${LIBFT} -o ${RES}
			cat ${AUTHOR}

all:		${NAME}

checker:	${C_OBJS}
			${MAKE} -C ./libft
			cp ./libft/libft.a ./
			ar -rcs checker.a ${C_OBJS}
			${CC} checker.a ${LIBFT} -o ${CHECKER}
			cat ${AUTHOR}

clean:		
			${RM} ${OBJS}
			${MAKE} fclean -C ./libft/
			${RM} ${LIBFT}
			${RM} ${NAME}

clean_checker:	
				${RM} ${C_OBJS}
				${MAKE} fclean -C ./libft/
				${RM} ${LIBFT}
				${RM} ${CHECKER}
				${RM} checker.a

reboot_checker:	clean_checker checker

fclean:		clean
			${RM} ./${RES}

re:			fclean all