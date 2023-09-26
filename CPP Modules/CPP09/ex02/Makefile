NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp VectorUtils.cpp DequeUtils.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Werror -Wextra

${NAME}:	${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all:	${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

clean:
	@rm -rf ${OBJS}

fclean:	clean
	@rm -rf ${NAME}

re:	fclean all