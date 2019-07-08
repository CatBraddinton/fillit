NAME := fillit
INCLUDES := fillit.h
FLAGS = -Wall -Wextra -Werror
SRC = 	main.c map.c add_to_list.c solver.c \
	 	inits_and_frees.c
OBJ := 	main.o map.o add_to_list.o solver.o\
		inits_and_frees.o
LIB := libft/libft.a
LIB_LIN := libft/libft.so
NAME_2 := fillit_t

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

termux: $(NAME_2)

$(NAME_2): $(OBJ) $(LIB_LIN)
	gcc $(FLAGS) -g -o $(NAME_2) $(OBJ) $(LIB_LIN)


$(OBJ): $(SRC) $(INCLUDES)
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDES) 

$(LIB):
	make -C libft/
$(LIB_LIN):
	make term -C libft/
clean:
	rm -rf $(OBJ)
	rm -rf *.h.gch \#*\# *~
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
