# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 13:14:43 by kdudko            #+#    #+#              #
#    Updated: 2019/07/11 13:14:47 by kdudko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit
INCLUDES := fillit.h
FLAGS = -Wall -Wextra -Werror
SRC = 	main.c get_tetriminos_list.c general_funcs.c\
		validate_tetriminos.c map.c solver.c
OBJ := 	main.o get_tetriminos_list.o general_funcs.o\
		validate_tetriminos.o map.o solver.o

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ): $(SRC) $(INCLUDES)
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDES) 

clean:
	rm -rf $(OBJ)
	rm -rf *.h.gch \#*\# *~

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
