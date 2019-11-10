# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 16:54:43 by dsandshr          #+#    #+#              #
#    Updated: 2019/11/10 14:11:13 by dsandshr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc -Wall -Wextra -Werror
SRC := visual.c create_list_step.c create_list_step2.c draw.c draw_text.c init_commands.c color_selection.c
NAME := vis
LIB := ../../libft/libft.a
LIB_H := ../../libft/include
SDL_LIB := ~/SDL2
INCLUDE := -I $(SDL_LIB)/SDL2.framework/Headers
FRAME := SDL2
SDL2 := -Wl,-rpath $(SDL_LIB) -F $(SDL_LIB) -framework $(FRAME)
OBJ := visual.o create_list_step.o create_list_step2.o draw.o draw_text.o init_commands.o color_selection.o

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) -c $(SRC) $(INCLUDE)
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) $(SDL2) -o $@;
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all