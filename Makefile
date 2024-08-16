# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vszpiech <vszpiech@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 17:54:20 by vszpiech          #+#    #+#              #
#    Updated: 2024/08/08 18:11:02 by vszpiech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

# Linking options
LINK = -Llibft -lft -L$(MLX_PATH) -lmlx -lXext -lX11 -lm

# MiniLibX library
MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = ${MLX_PATH}${MLX_NAME}

# Include paths
INC = -I ./include/\
      -I ./libft/\
      -I ./minilibx-linux/

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3

# Source files
UTILS = utils/ft_exit.c utils/ft_maths.c
SRCS = ${UTILS} src/main.c src/ft_errors.c src/ft_events.c src/ft_init.c src/ft_render.c
OBJS = ${SRCS:.c=.o}

# Rule to compile .o files from .c files
%.o : %.c
	${CC} ${CFLAGS} ${INC} -c $< -o $@

# Rule to build the final executable
${NAME} : ${OBJS}
	make -sC ${MLX_PATH}
	make -C libft/
	${CC} ${CFLAGS} ${INC} ${OBJS} ${MLX} ${LINK} -o ${NAME}

# Default target to build the project
all : ${NAME}

# Rule to clean object files
clean :
	rm -f ${OBJS}
	make clean -C libft/
	make clean -C ${MLX_PATH}

# Rule to clean everything including the final executable
fclean : clean
	make fclean -C libft/
	rm -f ${NAME}

# Rule to rebuild the project
re : fclean all

.PHONY : all clean fclean re
