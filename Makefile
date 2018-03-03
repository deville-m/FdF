# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:57:14 by mdeville          #+#    #+#              #
#    Updated: 2018/03/03 14:46:20 by mdeville         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
CC=clang
CFLAGS=-Wall -Wextra -O3
INCLUDES=-Iincludes/ -Ilibft/includes/
LIBDIR=libft/
LDFLAGS=-lmlx -framework OpenGL -framework AppKit

LIB=$(addprefix $(LIBDIR), libft.a)
SRC=	srcs/main.c \
		srcs/init.c \
		srcs/del_image.c \
		srcs/del_mlx.c \
		srcs/main.c \
		srcs/new_image.c \
		srcs/put_pixel.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(LIB):
	$(MAKE) -j8 -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@ $(LIB) $(LDFLAGS)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean
	$(MAKE)

.PHONY: re fclean clean all
