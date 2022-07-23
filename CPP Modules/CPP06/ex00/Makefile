# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 09:01:11 by makhtar           #+#    #+#              #
#    Updated: 2022/06/24 23:52:05 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

GREEN = "\033[3;32m"

SRCS = main.cpp ScalarConversion.cpp convert.cpp

OBJS = ${SRCS:%.cpp=%.o}

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror

${NAME}:${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}
	@echo ${GREEN}"           ██████ ██████  ██████      ███    ███  ██████  ██████  ██    ██ ██      ███████"
	@echo "          ██      ██   ██ ██   ██     ████  ████ ██    ██ ██   ██ ██    ██ ██      ██     "
	@echo "          ██      ██████  ██████      ██ ████ ██ ██    ██ ██   ██ ██    ██ ██      █████  "
	@echo "          ██      ██      ██          ██  ██  ██ ██    ██ ██   ██ ██    ██ ██      ██     "
	@echo "           ██████ ██      ██          ██      ██  ██████  ██████   ██████  ███████ ███████"
	@echo "                                                                                            "
	@echo "                                                                                            "
	@echo "                                    ██████   ██████                                           "
	@echo "                                   ██  ████ ██                                                "
	@echo "                                   ██ ██ ██ ███████                                           "
	@echo "                                   ████  ██ ██    ██                                          "
	@echo "                                    ██████   ██████                                           "

all:	${NAME}

clean:	
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all