NAME = fractol
CC = gcc
C_FLAGS = -Wall -Wextra -Werror -g

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
			
OBJ_DIR = obj
SRC_DIR = src
MLX_DIR = MLX42

INCLUDES = -Iinclude -I$(MLX_DIR)/include
LIB_MLX = $(MLX_DIR)/build/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:.c=.o)))

all: libmlx $(NAME)

libmlx:
	cmake MLX42 -B ./MLX42/build
	cmake --build ./MLX42/build -j4 

debug: $(NAME) dlibmlx

dlibmlx:
	cmake MLX42 -B ./MLX42/build -DDEBUG=1
	cmake --build ./MLX42/build -j4 

$(NAME): $(OBJ)
	$(CC) $^ $(LIB_MLX) -fsanitize=address $(INCLUDES) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
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
# gcc src/fractol.c MLX42/build/libmlx42.a  -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -IMLX42/include -Iinclude