#==============================================================================#
# CONFIG                                                                       #
#==============================================================================#

NAME = game

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -Iminilibx-linux

RM = rm -rf

LIBFT_DIR = ./inc/libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./inc/minilibx-linux

MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

#==============================================================================#
# SOURCE FILES                                                                 #
#==============================================================================#

SRC = src/main.c src/init.c src/render.c src/events.c src/utils.c

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

all: $(MLX) $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
	echo "Cloning MiniLibX..."; \
	git clone https://github.com/42paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I./inc

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Compilation Successful!$(RESET)"

clean:
	@if ls $(OBJ) 1> /dev/null 2>&1; then \
		$(RM) $(OBJ); \
		echo "$(GREEN)Intermediate object files removed:$(RESET)\n$(OBJ)"; \
	else \
		echo "$(RED)No object files to remove.$(RESET)"; \
	fi
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	@if [ -f $(NAME) ]; then \
		$(RM) $(NAME); \
		echo "$(GREEN)Compiled executable removed:$(RESET)\n$(NAME)"; \
	else \
		echo "$(RED)No executable to remove.$(RESET)"; \
	fi
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(RM) $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re

################################################################################
