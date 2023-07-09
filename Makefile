# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 20:42:20 by marvin            #+#    #+#              #
#    Updated: 2023/06/04 20:42:20 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft.a

SRCS =	./srcs/pipex.c \
		./srcs/pipex_utils.c \

OBJS :=$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME)
	@echo "$(GREEN)ok...pipex done!$(DEFAULT)"

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling libraries...$(DEFAULT)"
	@make -C ./mylibft
	@mv ./mylibft/$(LIBFT) .
	@cc $(CFLAGS) $(OBJS) -L. $(LIBFT) -o $(NAME)

clean:
	@make clean -C ./mylibft
	@rm -f $(LIBFT)
	@rm -f $(BNS_OBJS)
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Cleaning...yup, that's it!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re

#COLORS                                                                         
GREEN = \033[1;32m
RED = \033[1;31m
ORANGE = \033[38;5;208m
DEFAULT = \033[0m
YELLOW = \033[1;33m