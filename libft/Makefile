#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:18:07 by kdudko            #+#    #+#              #
#    Updated: 2018/11/12 15:19:47 by kdudko           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
LINUX_LIB = libft.so
INCLUDES := $(wildcard *.h)
FLAGS = -Wall -Wextra -Werror
SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

all: $(NAME)
termux: $(LINUX_LIB)

$(NAME): $(SRC) $(INCLUDES) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
$(LINUX_LIB):$(SRC) $(OBJ)
	gcc -shared -o $(LINUX_LIB) $(OBJ)
$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDES)

clean:
	rm -rf $(OBJ) $(LINUX_LIB)

fclean: clean
	rm -rf $(NAME) $(LINUX_LIB)


re: fclean all
