NAME := fillit
INCLUDES := fillit.h
FLAGS = -Wall -Wextra -Werror
SRC = 	main.c get_tetriminos_list.c general_funcs.c\
		validate_tetriminos.c map.c solver.c
OBJ := 	main.o get_tetriminos_list.o general_funcs.o\
		validate_tetriminos.o map.o solver.o
LIB := libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
$(OBJ): $(SRC) $(INCLUDES)
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDES) 
$(LIB):
	make -C libft/

clean:
	rm -rf $(OBJ)
	rm -rf *.h.gch \#*\# *~
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
