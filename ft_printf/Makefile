# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpole <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 12:11:32 by bpole             #+#    #+#              #
#    Updated: 2019/10/23 19:01:45 by bpole            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
      ft_fprintf.c \
	  parser.c \
	  output_c_s.c \
	  output_u.c \
	  output_i_d.c \
	  output_p.c \
	  output_persent.c \
	  output_o.c \
	  output_x.c \
	  output_f.c \
	  bonus_wildcard.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

HEAD = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all
