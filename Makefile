# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 03:21:46 by kdudko            #+#    #+#              #
#    Updated: 2019/07/18 09:14:13 by kdudko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit
INCLUDES := fillit.h
FLAGS = -Wall -Wextra -Werror
SRC = 	main.c get_tetriminos_list.c validate_tetriminos.c general_funcs.c\
		map.c fillit.c
OBJ := 	main.o get_tetriminos_list.o validate_tetriminos.o general_funcs.o\
		map.o fillit.o

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -g -o $(NAME) $(OBJ)

$(OBJ): $(SRC) $(INCLUDES)
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDES) 

clean:
	rm -rf $(OBJ)
	rm -rf *.h.gch \#*\# *~

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
