# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:57:14 by mdeville          #+#    #+#              #
#    Updated: 2018/03/06 14:51:09 by mdeville         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
CC=clang
CFLAGS=-Wall -Wextra -O3 -g
INCLUDES=-Iincludes/ -Ilibft/includes/
LIBDIR=libft/
LDFLAGS=-lmlx -framework OpenGL -framework AppKit

LIB=$(addprefix $(LIBDIR), libft.a)
SRC=	srcs/ft_graphics/init.c \
		srcs/ft_graphics/del_image.c \
		srcs/ft_graphics/del_mlx.c \
		srcs/ft_graphics/new_image.c \
		srcs/ft_graphics/put_pixel.c \
		srcs/ft_graphics/put_line.c \
		srcs/ft_graphics/init_hooks.c \
		srcs/ft_graphics/exit_x.c \
		srcs/print_x_map.c \
		srcs/free_line.c \
		srcs/print_map.c \
		srcs/parse.c \
		srcs/del_tab.c \
		srcs/main.c \
		srcs/mouse_press.c \
		srcs/mouse_release.c \
		srcs/mouse_hook.c

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
