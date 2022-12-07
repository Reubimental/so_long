UNAME := $(shell uname -s)
PATH_SRC = ./src/
PATH_GNL = $(PATH_SRC)gnl/
PATH_MAP = $(PATH_SRC)map/
PATH_UTILS = $(PATH_SRC)utils/
PATH_ERRORS = $(PATH_SRC)errors/
PATH_GAME = $(PATH_SRC)game/
PATH_MLX_Linux = ./mlx_linux/
PATH_MLX_Darwin = ./mlx_opengl/
PATH_OBJ = ./obj/

FLAGS_Darwin = -Lmlx_opengl -framework OpenGL -framework AppKit
MLX = $(PATH_MLX_$(UNAME))libmlx_$(UNAME).a
NAME = so_long

FILES = $(PATH_GAME)start.c			$(PATH_GAME)action.c		$(PATH_ERRORS)error.c		\
		$(PATH_MAP)init_sprites.c	$(PATH_MAP)map.c			$(PATH_MAP)render_map.c		\
		$(PATH_MAP)valid_map.c		$(PATH_MAP)verify.c			$(PATH_MAP)checks.c			\
		$(PATH_UTILS)ft_itoa.c		$(PATH_UTILS)ft_strlen.c	$(PATH_UTILS)ft_strdup.c	\
		$(PATH_GNL)get_next_line_utils.c	$(PATH_GNL)get_next_line.c $(PATH_GAME)move.c

OBJ = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(FILES))

CC = clang
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -I $(PATH_MLX_$(UNAME)) -L $(PATH_MLX_$(UNAME)) -lX11 -lXext
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo Object files made
	@make -C $(PATH_MLX_$(UNAME))
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(PATH_SRC)so_long.c $(OBJ) $(MLX) -o $(NAME)
	
$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJ)
	@mkdir -p $(PATH_OBJ)map
	@mkdir -p $(PATH_OBJ)gnl
	@mkdir -p $(PATH_OBJ)utils
	@mkdir -p $(PATH_OBJ)errors
	@mkdir -p $(PATH_OBJ)game
	$(CC) $(CFLAGS) -I. -c $< -o $@

bonus: all

clean:
	$(RM) $(PATH_OBJ)

fclean: clean
	make clean -C $(PATH_MLX_$(UNAME))
	$(RM) $(NAME)

re: fclean all

.PHONE: re all fclean clean

test:
	$(CC) -fsanitize=leak $(CFLAGS) $(MLXFLAGS) $(PATH_SRC)so_long.c $(FILES) -o $(NAME)
