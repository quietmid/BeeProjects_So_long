# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 16:05:56 by jlu               #+#    #+#              #
#    Updated: 2024/11/20 12:21:18 by jlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT = so long
NAME = so_long

LIBFT = ./libft/libft.a
MLX42 = ./MLX42/build/libmlx42.a

SRC = ./functions/so_long.c \
	  ./functions/path_check.c \
	  ./functions/move.c \
	  ./functions/map.c \
	  ./functions/map_utils.c \
	  ./functions/initializing.c \
	  ./functions/images_handler.c \
	  ./functions/fill_map.c \
	  ./functions/direction.c \
	  ./functions/utils.c \
	  ./functions/images_handler2.c \
	  ./functions/monster_bonus.c \
	  ./functions/screen_bonus.c \

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX42FLAGS = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
LIBMLX_DIR		=	./MLX42
LIBMLX			=	$(LIBMLX_DIR)/build/libmlx42.a

#Color ANSI Code 
BOLD   := \033[1m./SRC/
RED    := \033[31;1m
GREEN  := \033[32;1m
YELLOW := \033[33;1m
BLUE   := \033[34;1m
MAGENTA   := \033[35;1m
CYAN      := \033[36;1m
WHITE     := \033[37;1m
RESET     := \x1b[0m

OBJECTS_DIR = obj
OBJECTS = $(addprefix $(OBJECTS_DIR)/,$(notdir $(SRC:.c=.o)))

clone_mlx42:
	if [ ! -d "$(LIBMLX_DIR)/.git" ]; then \
		echo "Cloning MLX42..."; \
		rm -rf $(LIBMLX_DIR); \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX_DIR); \
	fi

# libmlx: clone_mlx42
# 	if [ ! -d "$(LIBMLX_DIR)/build" ]; then \
# 		cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build; \
# 	fi
# 	@make -C $(LIBMLX_DIR)/build -j4

libmlx: clone_mlx42
	if [ ! -d "$(LIBMLX_DIR)/build" ]; then \
		echo "Running cmake for MLX42..."; \
    	cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build; \
    fi
	@make -C $(LIBMLX_DIR)/build -j4

all: libmlx $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJECTS)
		@echo "Compiled with $(BLUE)$(CFLAGS)$(RESET)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(MLX42) $(MLX42FLAGS)
		@echo "$(CYAN)----------------------------------------"
		@echo "$(NAME) = NOW READY TO PLAY!"
		@echo "$(CYAN)----------------------------------------$(RESET)"

$(LIBFT):
		@$(MAKE) -C ./libft

$(MLX42):
		@$(MAKE) -C ./MLX42/build -j4

$(OBJECTS_DIR)/%.o: ./functions/%.c
		@mkdir -p $(OBJECTS_DIR)
		@echo "Compiled! $(CYAN) $^ $(RESET)"
		@$(CC) $(CFLAGS) -c -o $@ $^


clean:
		@$(MAKE) clean -C ./libft
		@if [ -d "$(LIBMLX_DIR)/build" ]; then \
        	$(MAKE) clean -C $(LIBMLX_DIR)/build; \
    	fi
		# @$(MAKE) clean -C ./MLX42/build
		@rm -rf $(OBJECTS_DIR)/*.o
		@rm -rf obj
		@echo "$(WHITE) $(OBJECTS_DIR) $(GREEN) REMOVED"

fclean: clean
		@$(MAKE) fclean -C ./libft
		# @$(MAKE) clean -C ./MLX42/build
		@if [ -d "$(LIBMLX_DIR)/build" ]; then \
    		$(MAKE) clean -C $(LIBMLX_DIR)/build; \
    	fi
		@rm -rf $(NAME)
		@echo "$(WHITE) $(PROJECT) $(RESET) $(GREEN) SO CLEANED"

re: fclean all

.PHONY: all clean fclean re
