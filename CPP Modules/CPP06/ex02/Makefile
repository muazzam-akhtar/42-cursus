# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 23:09:40 by makhtar           #+#    #+#              #
#    Updated: 2022/06/24 23:50:16 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = identify

GREEN = "\033[3;32m"

SRCS = main.cpp

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