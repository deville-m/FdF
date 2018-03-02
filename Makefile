# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:57:14 by mdeville          #+#    #+#              #
#    Updated: 2018/03/02 19:07:18 by mdeville         ###   ########.fr        #
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
