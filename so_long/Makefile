# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 10:00:22 by root              #+#    #+#              #
#    Updated: 2024/01/31 11:36:33 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = so_long

LIBFT = libft.a

PRINTF = libftprintf.a

LIBMLX = ./minilibx-linux/libmlx_Linux.a ./minilibx-linux/libmlx.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

LFLAGS = -L $(LIBMLX) $(LIBFT) $(PRINTF)

RM = rm -f

AR = ar -rsc

SRC = $(wildcard *.c) 

OBJ = $(SRC:.c=.o)

all: $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3  -c $< -o $@

$(NAME): $(OBJ)
	@make -C ./libft 
	@make -C ./printf
	@make -C ./minilibx-linux
	@mv ./libft/$(LIBFT) . 
	@mv ./printf/$(PRINTF) .
	$(CC) $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) libft.a libftprintf.a

clean:
	$(RM) $(OBJ)
	@make clean -C ./libft
	@make clean -C ./printf
	@make clean -C ./minilibx-linux


fclean: clean
	$(RM) $(NAME) $(LIBFT) $(PRINTF)

re: fclean all
	
.PHONY: all clean fclean re
	