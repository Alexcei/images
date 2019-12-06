# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpole <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 10:08:31 by bpole             #+#    #+#              #
#    Updated: 2019/12/06 00:28:49 by bpole            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual_fil

LIB_DIR = ./ft_printf/
LIB_DIR_X = ./minilibx_macos/

LIBFT = $(LIB_DIR)libftprintf.a
LIBFT_X = $(LIB_DIR_X)libmlx.a

SRC = main.c utils.c render.c bresenham.c control.c transform.c read_fight.c \
double_split.c head_map.c loop_key_hook.c mouse_press.c read_payer.c

OBJ = $(SRC:.c=.o)

INCLUDE = ./

CC = gcc

FLAGS =  -Wall -Wextra -Werror

FRAEM = -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $<

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(LIB_DIR_X)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBFT_X) $(FRAEM)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(LIB_DIR_X) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(LIB_DIR_X) fclean

re: fclean all
