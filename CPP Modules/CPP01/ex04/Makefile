# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/08 13:10:22 by makhtar           #+#    #+#              #
#    Updated: 2022/06/09 10:24:15 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sed

SRCS = srcs/main.cpp srcs/Sed.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:	
		rm -rf ${OBJS}
		rm -rf *.replace

fclean:	clean
		rm -rf ${NAME}

re:		fclean all