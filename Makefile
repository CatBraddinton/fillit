NAME := fillit
INCLUDES := fillit.h
FLAGS = -Wall -Wextra -Werror
SRC = 	main.c get_tetriminos_list.c general_funcs.c\
		validate_tetriminos.c map.c solver.c
OBJ := 	main.o get_tetriminos_list.o general_funcs.o\
		validate_tetriminos.o map.o solver.o
LIB := libft/libft.a


LIB_LIN := libft/libft.so
NAME_2 := fillit_termux
DEBUG := fillit_debug

all: $(NAME)
termux: $(NAME_2)
debug: $(DEBUG)

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
$(NAME_2): $(OBJ) $(LIB_LIN)
	gcc $(FLAGS) -g -o $(NAME_2) $(OBJ) $(LIB_LIN)
$(DEBUG): $(OBJ) $(LIB)
	gcc $(FLAGS) -g -o $(DEBUG) $(OBJ) $(LIB)
$(OBJ): $(SRC) $(INCLUDES)
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDES) 
$(LIB):
	make -C libft/
$(LIB_LIN):
	make termux -C libft/

clean:
	rm -rf $(OBJ)
	rm -rf *.h.gch \#*\# *~
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

dbclean: 
	rm -rf $(OBJ)
	rm -rf *.h.gch \#*\# *~
	rm -rf $(DEBUG)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
