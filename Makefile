# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsandshr <dsandshr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 18:21:34 by dsandshr          #+#    #+#              #
#    Updated: 2019/10/22 17:12:03 by dsandshr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	./players/dsandshr.filler
DIR_SRC				:=	src/
DIR_INCLUDE_FILLER	:=	./include
DIR_LIBFT			:=	./libft/
DIR_INCLUDE_LIBFT	:=	./libft/include
DIR_BIN				:=	bin/
DIRS_INCLUDE		:=	$(DIR_INCLUDE_FILLER) $(DIR_INCLUDE_LIBFT)

SRCS				:=	main.c \
						filler_info.c \
						fuck_actions.c

OBJS				:=	$(SRCS:.c=.o)
OBJ_WITH_DIR		:=	$(addprefix $(DIR_BIN), $(OBJS))
HEADERS				:=	filler.h
LIBFT				:=	libft.a

CFLAGS				:=	-Wextra -Werror -Wall -g
CFLAG				:=	-c
NFLAG				:=	-o
IFLAG				:=	-I
CC					:=	gcc

MAKE_LIBFT			:=	make -C $(DIR_LIBFT)
REMOVE				:=	rm -rf

vpath %.c $(DIR_SRC)
vpath %.o $(DIR_BIN)
vpath %.h $(DIR_INCLUDE_FILLER)
vpath %.a $(DIR_LIBFT)

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJ_WITH_DIR) $(NFLAG) $@ $(DIR_LIBFT)$(LIBFT)

$(OBJS): %.o:%.c $(HEADERS) | $(DIR_BIN)
		$(CC) $(CFLAG) $(CFLAGS) $< $(addprefix $(IFLAG), $(DIRS_INCLUDE)) $(NFLAG) $(DIR_BIN)$@

$(DIR_BIN):
		mkdir -p $@
$(LIBFT):
		$(MAKE_LIBFT)

clean:
		$(REMOVE) $(OBJ_WITH_DIR)
		$(REMOVE) $(DIR_BIN)
		$(MAKE_LIBFT) clean

fclean: clean
		$(REMOVE) $(NAME)
		$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: clean fclean re
.SILENT: all $(NAME) $(OBJS) $(DIR_BIN) $(LIBFT) clean fclean re