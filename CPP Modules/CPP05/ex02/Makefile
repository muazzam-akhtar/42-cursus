# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 01:16:21 by makhtar           #+#    #+#              #
#    Updated: 2022/06/20 10:58:54 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Forms

SRCS = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp

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