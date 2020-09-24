# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seongkim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 20:23:56 by seongkim          #+#    #+#              #
#    Updated: 2020/09/22 22:46:41 by seongkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I.
NAME		=	libftprintf.a
SRCS		=	srcs/ft_printf.c srcs/ft_printf_utils.c srcs/ft_itoa.c srcs/ft_parser.c srcs/ft_put.c \
				srcs/ft_handle_width.c srcs/ft_handle_char.c srcs/ft_handle_string.c srcs/ft_handle_percent.c \
				srcs/ft_handle_int.c srcs/ft_handle_unint.c srcs/ft_handle_hex.c srcs/ft_handle_pointer.c
OBJS		=	$(SRCS:.c=.o)
AR			=	ar
ARFLAGS		=	-rcs

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus : all
