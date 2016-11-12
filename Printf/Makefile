#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: kcosta <kcosta@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/12 17:12:33 by kcosta            #+#    #+#             *#
#*   Updated: 2016/11/12 17:44:10 by kcosta           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:%.c=%.o)
SRCSPATH = srcs/
SRCS = ft_printf.c


all: $(NAME)

%.o: $(SRCSPATH)%.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.PHONY: clean

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
