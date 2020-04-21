# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongkim <seongki@student.42seoul.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/21 17:11:45 by seongkim          #+#    #+#              #
#    Updated: 2020/04/21 22:20:20 by seongkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS = $(wildcard *lst*.c)
SRCS = $(filter-out $(BONUS), $(wildcard *.c))
OBJS = $(SRCS:.c=.o)
BONOBJS = $(BONUS: .c=.o)
NAME = libft.a
HEAD = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS) $(BONOBJS)
	$(AR) $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
