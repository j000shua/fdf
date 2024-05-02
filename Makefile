# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 12:27:08 by jlinguet          #+#    #+#              #
#    Updated: 2024/05/02 18:09:05 by jlinguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC = fdf.h

SRC = fdf.c \
      mlx_letsgo.c \
	  draw_line.c \
	  parse_file.c
vpath %.c $(dir $(SRC))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir ${SRC:.c=.o}))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I.

MLXFLAGS = -L../minilibx -lmlx -lXext -lX11 -lm

$(OBJ_DIR)/%.o: %.c $(INC)
	@mkdir -p ${OBJ_DIR}
	${CC} ${CFLAGS} -c $< -o $@ 

${NAME} : ${OBJ} 
	@make -C libft
	${CC} ${CFLAGS}  $^ -o ${NAME} -Llibft -lft $(MLXFLAGS)

all : ${NAME}

clean :
	make $@ -C libft
	rm -rf ${OBJ_DIR}

fclean : clean
	make $@ -C libft
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
