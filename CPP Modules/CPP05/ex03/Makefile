# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 01:16:21 by makhtar           #+#    #+#              #
#    Updated: 2022/06/22 11:30:30 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

SRCS = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

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