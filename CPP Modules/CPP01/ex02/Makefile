# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 13:08:47 by makhtar           #+#    #+#              #
#    Updated: 2022/06/08 13:08:47 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror

${NAME}:${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:	fclean all
