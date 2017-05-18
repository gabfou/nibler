# **************************************************************************** #
#	                                                                           #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/23 23:09:04 by jromagna          #+#    #+#              #
#    Updated: 2016/03/28 23:40:51 by ibuchwal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibler

SRC =	main.c \

OBJ = $(SRC:.c=.o)
CC = g++
CFLAGS = -Wall -Wextra -Werror # -fsanitize=address
LFLAGS = 

all: $(NAME)

$(NAME): $(OBJ)
	# @echo "libft start"
	# @make -C libft
	# @echo "libft ok"
	@echo "comp start"
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)
	@echo "ALL DONE"

norm:
	norminette **[ch]

clean:
	@echo "cleaning .o"
	@/bin/rm -f $(OBJ)
	@make -C libft clean
	@echo "cleaning .o done"

fclean: clean
	@echo "cleaning NAME"
	@/bin/rm -f $(NAME)
	@make -C libft fclean
	@echo "cleaning NAME done"

re: fclean all
