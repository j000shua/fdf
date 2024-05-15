# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlinguet <jlinguet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 12:27:08 by jlinguet          #+#    #+#              #
#    Updated: 2024/05/16 00:07:38 by jlinguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC = fdf.h

SRC = fdf.c \
	parse_file.c \
	mlx_letsgo.c
vpath %.c $(dir $(SRC))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir ${SRC:.c=.o}))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I.

MLXFLAGS = -L../mlx -lmlx -lXext -lX11 -lm

$(OBJ_DIR)/%.o: %.c $(INC)
	@mkdir -p ${OBJ_DIR}
	${CC} ${CFLAGS} -c $< -o $@ 

all : libft ${NAME} 

${NAME} : ${OBJ} libft/libft.a
	${CC} ${CFLAGS}  $^ -o ${NAME} -Llibft -lft $(MLXFLAGS)

clean :
	make $@ -C libft
	rm -rf ${OBJ_DIR}

fclean : clean
	make $@ -C libft
	rm -f ${NAME}

re : fclean all

libft :
	make -C libft

.PHONY : all clean fclean re libft
