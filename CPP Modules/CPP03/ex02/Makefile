NAME = FragTrap

SRCS = srcs/main.cpp srcs/ClapTrap.cpp srcs/FragTrap.cpp srcs/ScavTrap.cpp

OBJS = ${SRCS:%.cpp=%.o}

CXX = c++ -std=c++98 -ggdb

CXXFLAGS = -Wall -Wextra -Werror

${NAME}:${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:	
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all