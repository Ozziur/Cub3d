# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 19:02:32 by mruizzo           #+#    #+#              #
#    Updated: 2023/01/25 19:12:09 by mruizzo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS	= libs/Get_Next_Line/get_next_line_utils.o libs/Get_Next_Line/get_next_line.o libs/string.o srcs/game/bres_algo.o srcs/game/colliding.o srcs/game/events.o srcs/game/game.o srcs/game/loop_event.o srcs/game/minimap.o srcs/game/moves.o srcs/game/raycast_calc.o srcs/game/raycast.o srcs/game/render.o srcs/parsing/check.o srcs/parsing/get_rules.o srcs/parsing/parse_map.o srcs/utils/choose.o srcs/utils/easy_math.o srcs/utils/error_and_debug.o srcs/utils/img_utils.o srcs/utils/init.o srcs/utils/math_stuff.o srcs/main.o
SOURCE	= libs/Get_Next_Line/get_next_line_utils.c libs/Get_Next_Line/get_next_line.c libs/string.c srcs/game/bres_algo.c srcs/game/colliding.c srcs/game/events.c srcs/game/game.c srcs/game/loop_event.c srcs/game/minimap.c srcs/game/moves.c srcs/game/raycast_calc.c srcs/game/raycast.c srcs/game/render.c srcs/parsing/check.c srcs/parsing/get_rules.c srcs/parsing/parse_map.c srcs/utils/choose.c srcs/utils/easy_math.c srcs/utils/error_and_debug.c srcs/utils/img_utils.c srcs/utils/init.c srcs/utils/math_stuff.c srcs/main.c
HEADER	= incl/cub3d.h incl/get_next_line.h incl/libft.h
NAME	= cub3d
CC 		= @gcc
CFLAGS 	= -g -O -I -Wall -Werror -Wextra
MLXFLAG = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(MLXFLAG)

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	@printf "removing Object files...\n"
	@/bin/rm -f $(OBJS)
	@printf "\033[0;35mObject files removed!\n"
	@echo "\033[0;37m"

fclean: clean
	@printf "removing program executable...\n"
	@/bin/rm -f ./cub3d
	@/bin/rm -rf bin
	@printf "\033[0;35mExecutable removed!\n"
	@echo "\033[0;37m"

re: fclean all