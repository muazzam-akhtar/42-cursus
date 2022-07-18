# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 16:56:04 by makhtar           #+#    #+#              #
#    Updated: 2021/12/15 20:38:04 by makhtar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long.a

AUTHOR = author.txt

RED = \033[0;31m

LIBFT = libft.a

MLX	  = libmlx.a

MLXFLAGS = -framework OpenGL -framework AppKit

RES		= so_long
			
SRCS	= so_long.c materials.c game_functions.c controls.c init.c map_work.c player.c \
			go.c window.c

B_SRCS 	= so_long_bonus.c materials_bonus.c game_functions_bonus.c controls_bonus.c init_bonus.c map_work_bonus.c player_bonus.c \
			go_bonus.c window_bonus.c killer.c idle_sprite.c collect_sprite.c \
			killer_locator.c dead_sprite.c

OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${B_SRCS:.c=.o}

CC = gcc -Wall -Wextra -Werror

RM = rm -rf

${NAME} : 	${OBJS}
			${MAKE} all -C ./libft/
			${MAKE} all -C ./minilibx
			cp ./libft/libft.a ./
			cp ./minilibx/libmlx.a ./
			ar -rcs ${NAME} ${OBJS}
			${CC} ${MLXFLAGS} ${NAME} ${LIBFT} ${MLX} -o ${RES}
	@echo "${RED}                        8Xt                                                "
	@echo "${RED}                        X@..                                               "
	@echo "${RED}             %88S...@8X 88@t8@88S                                          "
	@echo "${RED}        tttSS% . %% . .t t%   S88. SX@                                     "
	@echo "${RED}       t8 %%t %%t.  .  %%tSt @ 8SSt%S@                                     "
	@echo "${RED}     8  .tt  XSS88 . . St% 8.S8X .S8t                                      "
	@echo "${RED}   tt.t .8X8S. X@.@  8  .X8% . 8t                                          "
	@echo "${RED}   .8% @8.. S8.  t ..    t88S               S. .   @X                      "
	@echo "${RED}  X@t%. %8t8t        .%@88@               t 8  . SXSStt                    "
	@echo "${RED} .    %X8t              X8t.              8 .. .. %8Xt.X                   "
	@echo "${RED} ..8%X                  S8               X% %@.t@ t@88%.X  8X@             "
	@echo "${RED}  88                  . @8S             . .. S %% t8888S% .8  %            "
	@echo "${RED}                      @  8 X            . % ...  .S8888Xt@@XS t            "
	@echo "${RED}                     . S@8               t S    t%88@88888@8% .            "
	@echo "${RED}                      S.88 .           tS8t@88888%S8%SXX@XXtS8             "
	@echo "${RED}                        @8..        %@%S8S88@888@@SSXtt@.X %%              "
	@echo "${RED}                        8@@8888 XSS 8XSS888XS8S888S%S%%@t.                 "
	@echo "${RED}                      @ X  8t %tS%S@888@88XS%X888S88@8SS  %                "
	@echo "${RED}                     . t88SSX8t@8@888888XX%%@@8888@8X@@X8%8                "
	@echo "${RED}                      % 888X 8@S888888888%X 8888888@8ttX@S8t               "
	@echo "${RED}                      .S8@@  t8%88@@8S  S .@S88@888S t%X88SSS              "
	@echo "${RED}                        S.Xt8 8t%S .8t     XS88@88@%%%t@888XX8.            "
	@echo "${RED}                      .  S@ 8 8@@  ..      X%8888X8@ @ X8888%X             "
	@echo "${RED}                        8t  @ X8@          SS@8X88@S .S@S88@%S8            "
	@echo "${RED}                        8  X8X             X 88888@St8 @%8@%%% 8           "
	@echo "${RED}                      @ @SSS8X            %. X88@8XX%@.X@S88XS 8           "
	@echo "${RED}                     %  . 8               % 8@St %8Xt@. S@X  8.@X          "
	@echo "${RED}                      @88                .S tSSX%SS%8    8   88@X.         "
	@echo "${RED}                      St8.                .SS@@8@88@ @  %8X  8@@8          "
	@echo "${RED}                        8@%.              . t@8888@XtS8  .                 "
	@echo "${RED}                        X8.              t  S8@88888X@S                    "
	@echo "${RED}                      .8@8               t S88@X8888XX@t 8@                "
	@echo "${RED}                       @   %             .%t@888888888%St%8 8ttt           "
	@echo "${RED}                        888              @%%SSX8X%SX8@SS8Xt tt8888   8%%   "
	@echo "${RED}                       @8X88            XS X8@%t XX88SttStt8SSt   @888.8@  "
	@echo "${RED}                       S 8X@            8 %8XX8@X@%%XX@XS@%ttSStX8@SX%8    "
	@echo "${RED}                       ..888            @X  S  S % X @   ..  %%%S%         "
	@echo "${RED}                        SS8X             .  .                              "
	@echo "${RED}                         %.                                                "

	@echo "${RED}       ▄████████  ▄██████▄        ▄█        ▄██████▄  ███▄▄▄▄      ▄██████▄  "
	@echo "${RED}      ███    ███ ███    ███      ███       ███    ███ ███▀▀▀██▄   ███    ███ "
	@echo "${RED}      ███    █▀  ███    ███      ███       ███    ███ ███   ███   ███    █▀  "
	@echo "${RED}      ███        ███    ███      ███       ███    ███ ███   ███  ▄███        "
	@echo "${RED}    ▀███████████ ███    ███      ███       ███    ███ ███   ███ ▀▀███ ████▄  "
	@echo "${RED}             ███ ███    ███      ███       ███    ███ ███   ███   ███    ███ "
	@echo "${RED}       ▄█    ███ ███    ███      ███▌    ▄ ███    ███ ███   ███   ███    ███ "
	@echo "${RED}     ▄████████▀   ▀██████▀       █████▄▄██  ▀██████▀   ▀█   █▀    ████████▀  "
	@echo "${RED}                                 ▀                                           "
	@cat ${AUTHOR}

all: 		${NAME}

bonus:	${B_OBJS}
		${MAKE} all -C ./libft/
		${MAKE} all -C ./minilibx
		cp ./libft/libft.a ./
		cp ./minilibx/libmlx.a ./
		ar -rcs ${NAME} ${B_OBJS}
		${CC} ${MLXFLAGS} ${NAME} ${LIBFT} ${MLX} -o ${RES}
	@echo "${RED}                        8Xt                                                "
	@echo "${RED}                        X@..                                               "
	@echo "${RED}             %88S...@8X 88@t8@88S                                          "
	@echo "${RED}        tttSS% . %% . .t t%   S88. SX@                                     "
	@echo "${RED}       t8 %%t %%t.  .  %%tSt @ 8SSt%S@                                     "
	@echo "${RED}     8  .tt  XSS88 . . St% 8.S8X .S8t                                      "
	@echo "${RED}   tt.t .8X8S. X@.@  8  .X8% . 8t                                          "
	@echo "${RED}   .8% @8.. S8.  t ..    t88S               S. .   @X                      "
	@echo "${RED}  X@t%. %8t8t        .%@88@               t 8  . SXSStt                    "
	@echo "${RED} .    %X8t              X8t.              8 .. .. %8Xt.X                   "
	@echo "${RED} ..8%X                  S8               X% %@.t@ t@88%.X  8X@             "
	@echo "${RED}  88                  . @8S             . .. S %% t8888S% .8  %            "
	@echo "${RED}                      @  8 X            . % ...  .S8888Xt@@XS t            "
	@echo "${RED}                     . S@8               t S    t%88@88888@8% .            "
	@echo "${RED}                      S.88 .           tS8t@88888%S8%SXX@XXtS8             "
	@echo "${RED}                        @8..        %@%S8S88@888@@SSXtt@.X %%              "
	@echo "${RED}                        8@@8888 XSS 8XSS888XS8S888S%S%%@t.                 "
	@echo "${RED}                      @ X  8t %tS%S@888@88XS%X888S88@8SS  %                "
	@echo "${RED}                     . t88SSX8t@8@888888XX%%@@8888@8X@@X8%8                "
	@echo "${RED}                      % 888X 8@S888888888%X 8888888@8ttX@S8t               "
	@echo "${RED}                      .S8@@  t8%88@@8S  S .@S88@888S t%X88SSS              "
	@echo "${RED}                        S.Xt8 8t%S .8t     XS88@88@%%%t@888XX8.            "
	@echo "${RED}                      .  S@ 8 8@@  ..      X%8888X8@ @ X8888%X             "
	@echo "${RED}                        8t  @ X8@          SS@8X88@S .S@S88@%S8            "
	@echo "${RED}                        8  X8X             X 88888@St8 @%8@%%% 8           "
	@echo "${RED}                      @ @SSS8X            %. X88@8XX%@.X@S88XS 8           "
	@echo "${RED}                     %  . 8               % 8@St %8Xt@. S@X  8.@X          "
	@echo "${RED}                      @88                .S tSSX%SS%8    8   88@X.         "
	@echo "${RED}                      St8.                .SS@@8@88@ @  %8X  8@@8          "
	@echo "${RED}                        8@%.              . t@8888@XtS8  .                 "
	@echo "${RED}                        X8.              t  S8@88888X@S                    "
	@echo "${RED}                      .8@8               t S88@X8888XX@t 8@                "
	@echo "${RED}                       @   %             .%t@888888888%St%8 8ttt           "
	@echo "${RED}                        888              @%%SSX8X%SX8@SS8Xt tt8888   8%%   "
	@echo "${RED}                       @8X88            XS X8@%t XX88SttStt8SSt   @888.8@  "
	@echo "${RED}                       S 8X@            8 %8XX8@X@%%XX@XS@%ttSStX8@SX%8    "
	@echo "${RED}                       ..888            @X  S  S % X @   ..  %%%S%         "
	@echo "${RED}                        SS8X             .  .                              "
	@echo "${RED}                         %.                                                "

	@echo "${RED}       ▄████████  ▄██████▄        ▄█        ▄██████▄  ███▄▄▄▄      ▄██████▄  "
	@echo "${RED}      ███    ███ ███    ███      ███       ███    ███ ███▀▀▀██▄   ███    ███ "
	@echo "${RED}      ███    █▀  ███    ███      ███       ███    ███ ███   ███   ███    █▀  "
	@echo "${RED}      ███        ███    ███      ███       ███    ███ ███   ███  ▄███        "
	@echo "${RED}    ▀███████████ ███    ███      ███       ███    ███ ███   ███ ▀▀███ ████▄  "
	@echo "${RED}             ███ ███    ███      ███       ███    ███ ███   ███   ███    ███ "
	@echo "${RED}       ▄█    ███ ███    ███      ███▌    ▄ ███    ███ ███   ███   ███    ███ "
	@echo "${RED}     ▄████████▀   ▀██████▀       █████▄▄██  ▀██████▀   ▀█   █▀    ████████▀  "
	@echo "${RED}                                 ▀                                           "
	@cat ${AUTHOR}

clean:
		${MAKE} fclean -C ./libft/
		${MAKE} clean -C ./minilibx/
		${RM} ${OBJS}
		${RM} ${B_OBJS}
		${RM} ./${RES}
		${RM} ${LIBFT}
		${RM} libmlx.a

fclean: clean
			${RM} ${NAME}

re :		fclean all

rebonus:	fclean bonus
