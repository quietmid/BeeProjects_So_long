# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlu <jlu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 18:20:27 by jlu               #+#    #+#              #
#    Updated: 2023/11/28 16:32:11 by jlu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_print_char.c \
	  ft_print_digit.c \
	  ft_print_str.c \
	  ft_print_hex.c \
	  ft_print_ptr.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) 
	
re: fclean all 

.PHONY: all clean fclean re
