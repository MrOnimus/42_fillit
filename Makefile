# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 15:08:51 by dbutterw          #+#    #+#              #
#    Updated: 2019/09/28 22:06:09 by dbutterw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src

OBJ_DIR = ./obj

SRC     = ft_get_coords.c ft_read_elems.c ft_valid_elem.c ft_rev_elems.c \
ft_free_elems.c ft_map_general.c ft_map_operations.c main.c

OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

HEAD	= ./includes

NAME    = fillit

CFLAGS  = -I $(HEAD) -Wall -Wextra -Werror

LFLAGS  = -L libft/ -lft

.PHONY: all lib clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | lib
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ) | lib
	gcc $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJ)

lib:
	make -C ./libft

clean:
	make clean -C ./libft
	rm -rf $(OBJ_DIR)
	rm -f *~
	rm -f \#*\#

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
