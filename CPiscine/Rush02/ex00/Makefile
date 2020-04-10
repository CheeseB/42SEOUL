# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinlee <jinlee@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 20:48:25 by jinlee            #+#    #+#              #
#    Updated: 2020/02/09 21:05:26 by jinlee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard ./srcs/*.c)
OBJS = $(SRCS:.c=.o)
TARGET = rush-02
HEADS = ./includes/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -I $(HEADS) -o $(<:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) 

.PHONY: all clean fclean re

all: $(TARGET)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
