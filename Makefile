# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 16:05:56 by jlu               #+#    #+#              #
#    Updated: 2024/02/02 13:49:42 by jlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT = so long
NAME = so_long

LIBFT = ./libft/libft.a
MLX42 = ./MLX42/libmlx42.a

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

all: $(NAME)

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
		@$(MAKE) clean -C ./MLX42/build
		@rm -rf $(OBJECTS_DIR)/*.o
		@if [ -f "$(OBJECTS_DIR)" ]; then rmdir -p $(OBJECTS_DIR); fi
		@echo "$(WHITE) $(OBJECTS_DIR) $(GREEN) REMOVED"

fclean: clean
		@$(MAKE) fclean -C ./libft
		@$(MAKE) clean -C ./MLX42/build
		@rm -rf $(NAME)
		@echo "$(WHITE) $(PROJECT) $(RESET) $(GREEN) SO CLEANED"

re: fclean all

.PHONY: all clean fclean re 
