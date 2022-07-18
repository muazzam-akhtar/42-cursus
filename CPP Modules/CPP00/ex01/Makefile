# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 12:10:43 by makhtar           #+#    #+#              #
#    Updated: 2022/06/06 12:10:44 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

# .SILENT:

SRCS = srcs/main.cpp srcs/add_contact.cpp srcs/contact_class.cpp srcs/show_phonebook.cpp

INCLUDES = includes/

OBJS = ${SRCS:.cpp=.o}

CXX = c++ -std=c++98 -I ${INCLUDES}

CXXFLAGS = -Wall -Wextra -Werror

${NAME}:	${OBJS}
			${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}
			@echo "\033[01;32m"
			@cat phonebook.txt
			@echo "\033[0m"

all:	${NAME}

clean:	
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all
			