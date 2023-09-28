NAME = fractol
CC = cc
C_FLAGS = -Wall -Wextra -Werror -Ofast -arch arm64

SRC_FILES = fractol.c \
			input_check.c \
			init.c \
			double_conversion.c \
			key_hooks.c \
			scroll_hook.c \
			mandelbrot.c \
			julia.c \
			draw.c \
			colour.c \
			utils.c \
			resize.c  \
			burning_ship.c \
			atoi.c \
			error.c

OBJ_DIR = obj
SRC_DIR = src
MLX_DIR = MLX42

INCLUDES = -Iinclude -I$(MLX_DIR)/include
LIB_MLX = $(MLX_DIR)/build/libmlx42.a

#F_SAN = -g -fsanitize=address

ifeq ($(shell uname -m),arm64)
MLX_FLAGS = -L/opt/homebrew/lib -lglfw -framework IOKit -framework Cocoa
else ifeq ($(shell uname -m),x86_64)
MLX_FLAGS = -lglfw3 -framework IOKit -framework Cocoa
endif

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(LIB_MLX):
	@cmake MLX42 -B ./MLX42/build
	@cmake --build ./MLX42/build -j4

debug: $(NAME) dlibmlx

dlibmlx:
	cmake MLX42 -B ./MLX42/build -DDEBUG=1
	cmake --build ./MLX42/build -j4

$(NAME): $(OBJ) $(LIB_MLX)
	@$(CC) $(C_FLAGS) $^ $(LIB_MLX) $(MLX_FLAGS) $(INCLUDES) -o $@
	@echo "fractol made!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(C_FLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(LIBMLX)/build
	@echo "cleaned!"

fclean: clean
	@rm -rf $(NAME)
	@echo "fcleaned!"

re: fclean all

.PHONY: all clean fclean re
