CC = @gcc
CFLAGS = -I -Wall -Werror -Wextra
READLINE_FLAGS = CC = @gcc
CFLAGS = -I -Wall -Werror -Wextra
READLINE_FLAGS = -lmlx -framework OpenGL -framework AppKit

INCLUDES = $(shell find . -name "*.h" -print)

OBJS_DIR = bin
OBJS_NOPREFIX = $(shell find . -name "*.c" -print | sed 's/\.c/\.o/g' | sed 's/\.\///')# last cmd removes ./ at the beginning of each file
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NOPREFIX))

NAME = cub3d

all: .BUILD

bonus: .BUILD

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(READLINE_FLAGS)
	@printf "\033[1m\033[32mCub3d Compiled!\n"
	@echo "\033[0;37m"

#
#	this rule compiles sources in <path>.c and puts them in <obj_dir>/<path>.o
#
#
$(shell echo $(OBJS_DIR))/%.o: %.c $(INCLUDES)
	@mkdir -p '$(@D)'
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@printf "removing Object files...\n"
	@/bin/rm -f $(OBJS)
	@printf "\033[0;35mObject files removed!\n"
	@echo "\033[0;37m"

fclean: clean
	@printf "removing program executable...\n"
	@/bin/rm -f ./minishell
	@/bin/rm -rf bin
	@printf "\033[0;35mExecutable removed!\n"
	@echo "\033[0;37m"

re: fclean all

git:
	make fclean
	git add .
	git commit -m cub3d
	git push

.BUILD:
	@printf "\033[1m\033[33mMaking Project...\033[0m\n"
	@$(MAKE) $(NAME)

OBJS_DIR = bin
OBJS_NOPREFIX = $(shell find . -name "*.c" -print | sed 's/\.c/\.o/g' | sed 's/\.\///')# last cmd removes ./ at the beginning of each file
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NOPREFIX))

