# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 13:06:22 by makhtar           #+#    #+#              #
#    Updated: 2022/06/08 13:06:23 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRCS = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp

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