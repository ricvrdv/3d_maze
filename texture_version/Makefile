#==============================================================================#
# CONFIG                                                                       #
#==============================================================================#

NAME = game

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -Iminilibx

RM = rm -rf

MLX_DIR = ./inc/minilibx

MLX = $(MLX_DIR)/libmlx.all

MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

#==============================================================================#
# SOURCE FILES                                                                 #
#==============================================================================#

SRC = src/main.c \
	src/player.c \
	src/draw.c \
	src/texture.c

OBJ = $(SRC:.c=.o)

#==============================================================================#
# COLORS                                                                       #
#==============================================================================#

RED = \033[1;31m

GREEN = \033[1;32m

RESET = \033[0m

#==============================================================================#
# RULES                                                                        #
#==============================================================================#

all: $(MLX) $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I./inc

$(NAME): $(OBJ) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Compilation Successful!$(RESET)"

clean:
	@if ls $(OBJ) 1> /dev/null 2>&1; then \
		$(RM) $(OBJ); \
		echo "$(GREEN)Intermediate object files removed:$(RESET)\n$(OBJ)"; \
	else \
		echo "$(RED)No object files to remove.$(RESET)"; \
	fi
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	@if [ -f $(NAME) ]; then \
		$(RM) $(NAME); \
		echo "$(GREEN)Compiled executable removed:$(RESET)\n$(NAME)"; \
	else \
		echo "$(RED)No executable to remove.$(RESET)"; \
	fi
	@$(MAKE) clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re

################################################################################
