# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 19:02:32 by mruizzo           #+#    #+#              #
#    Updated: 2023/02/09 17:23:42 by anovelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3d
NAME_B  = cub3d_bonus
SRCS    = libs/Get_Next_Line/get_next_line_utils.c libs/Get_Next_Line/get_next_line.c \
		 libs/string.c srcs/game/bres_algo.c srcs/game/colliding.c srcs/game/events.c \
		 srcs/game/game.c srcs/game/loop_event.c srcs/game/moves.c \
		 srcs/game/raycast_calc.c srcs/game/raycast.c srcs/game/render.c srcs/parsing/check.c \
		 srcs/parsing/get_rules.c srcs/parsing/parse_map.c srcs/utils/choose.c srcs/utils/easy_math.c \
		 srcs/utils/error_and_debug.c srcs/utils/img_utils.c srcs/utils/init.c srcs/utils/math_stuff.c srcs/main.c srcs/parsing/check_utils.c
B_SRCS  = 	bonus/utils/choose.c \
			bonus/utils/door_utils.c \
			bonus/utils/easy_math.c \
			bonus/utils/error_and_debug.c \
			bonus/utils/img_utils.c \
			bonus/utils/init.c \
			bonus/utils/math_stuff.c \
			bonus/utils/sort_sprite.c \
			bonus/utils/sprite_utils.c \
			bonus/utils/sprite.c \
			bonus/main.c \
			bonus/parsing/check_utils.c \
			bonus/parsing/check_utils2.c \
			bonus/parsing/check.c \
			bonus/parsing/get_rules.c \
			bonus/parsing/parse_map.c \
			bonus/libs/Get_Next_Line/get_next_line_utils.c \
			bonus/libs/Get_Next_Line/get_next_line.c \
			bonus/libs/libs_utils.c \
			bonus/libs/string.c \
			bonus/game/bres_algo.c \
			bonus/game/colliding.c \
			bonus/game/doors.c \
			bonus/game/draw_sprite.c \
			bonus/game/events.c \
			bonus/game/game.c \
			bonus/game/loop_event.c \
			bonus/game/minimap.c \
			bonus/game/mouse.c \
			bonus/game/moves.c \
			bonus/game/raycast_calc.c \
			bonus/game/raycast.c \
			bonus/game/render.c \
			bonus/game/win.c    \
			bonus/game/draw_sprite_utils.c \


CC      = @gcc
CFLAGS  = -g -O3 -I -Wall -Werror -Wextra
MLXFLAG = -lmlx -framework OpenGL -framework AppKit
SRCS_DIR        = ./srcs
OBJS_DIR        = ./objs
OBJS            = $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS:.c=.o))
B_OBJS          = $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(B_SRCS:.c=.o))

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(MLXFLAG)

$(NAME_B): $(B_OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(MLXFLAG)

clean:
	@rm -f $(OBJS)
	@rm -f $(B_OBJS)
fclean: clean
	@printf "removing program executable...\n"
	@/bin/rm -f ./cub3d
	@/bin/rm -f ./cub3d_bonus
	@/bin/rm -rf bin
	@printf "\033[0;35mExecutable removed!\n"
	@echo "\033[0;37m"
	
git:
	make fclean
	git add .
	git commit -m cub3d
	git push
re: fclean all
bre: fclean bonus
my: all clean