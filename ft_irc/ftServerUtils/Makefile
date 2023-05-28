# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 23:57:52 by wismith           #+#    #+#              #
#    Updated: 2023/05/01 17:28:38 by wismith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ServerUtils.a

CXX = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -g3

SRCS = SetSocket \
	Listener \
	error \
	log \

OBJDIR = objects

OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))

$(OBJDIR)/%.o : srcs/%.cpp
	@mkdir -p $(OBJDIR)
	@printf "\033[A\033[2K\r"

	@tput setaf 2
	@printf "\tGenerating ... "
	@tput init

	$(CXX) $(CPPFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : printHead $(OBJ)
	@printf "\033[A\033[2K\r"
	@tput setaf 2
	@printf "\tGenerating ... "
	@tput init
	ar -rc $(NAME) $(OBJ)

	@printf "\033[A\033[2K\r"

	@tput setaf 2
	@printf "\tArchived ServerUtils.a\n"
	@tput init

clean :
	@rm -rf $(OBJDIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

printHead :
	@printf " _______________________________________________________\n"
	@printf "|                                                       |\n"
	@printf "|";

	@tput setaf 2
	@printf "     \"THE MOMENT WE STOP LEARNING IS THE MOMENT WE     "
	@tput init

	@printf "|\n"
	@printf "|";

	@tput setaf 2
	@printf "    STAGNATE, AND THOUGH LEARNING IN THE REAL WORLD    "
	@tput init

	@printf "|\n"
	@printf "|"

	@tput setaf 2
	@printf "     IS SELDOM UNACCOMPANIED BY HARDSHIP IT'S ALSO     "
	@tput init

	@printf "|\n"
	@printf "|"

	@tput setaf 2
	@printf "          AN EXPERIENCE.\" - Willem J. Smith            "
	@tput init

	@printf "|\n"
	@printf "|_______________________________________________________|\n"
	@printf "\n\n"

.PHONY : all clean fclean re printHead