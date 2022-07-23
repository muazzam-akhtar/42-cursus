# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 11:02:40 by makhtar           #+#    #+#              #
#    Updated: 2022/06/20 10:20:45 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Abstract

SRCS = main.cpp Cat.cpp Dog.cpp AAnimal.cpp Brain.cpp

OBJS = ${SRCS:%.cpp=%.o}

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Werror -Wextra

${NAME}:${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:	
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all