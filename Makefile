# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 13:14:43 by kdudko            #+#    #+#              #
#    Updated: 2019/07/14 23:58:19 by kdudko           ###   ########.fr        #
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
