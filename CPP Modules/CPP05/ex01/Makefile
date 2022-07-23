# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 01:16:21 by makhtar           #+#    #+#              #
#    Updated: 2022/06/21 11:21:23 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form

SRCS = main.cpp Bureaucrat.cpp Form.cpp

OBJS = ${SRCS:%.cpp=%.o}

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror

${NAME}:${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:	
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all