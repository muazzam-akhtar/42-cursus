# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 13:08:58 by makhtar           #+#    #+#              #
#    Updated: 2022/06/08 13:09:48 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec

INCLUDES = includes

SRCS = srcs/main.cpp \
		srcs/HumanA.cpp \
		srcs/HumanB.cpp \
		srcs/Weapon.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror

${NAME}:	${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all