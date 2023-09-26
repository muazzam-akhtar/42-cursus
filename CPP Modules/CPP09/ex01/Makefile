NAME = RPN

SRCS = main.cpp RPN.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Werror -Wextra

${NAME}:	${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
	@rm -rf ${OBJS}

fclean:	clean
	@rm -rf ${NAME}

re:	fclean all