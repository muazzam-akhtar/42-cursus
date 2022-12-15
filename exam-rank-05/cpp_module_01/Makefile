NAME = a.out

SRCS = Warlock.cpp main.cpp ASpell.cpp ATarget.cpp Fwoosh.cpp Dummy.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Werror -Wextra

${NAME}: ${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	@rm -rf ${OBJS}

fclean:	clean
	@rm -rf ${NAME}

re:	fclean all
