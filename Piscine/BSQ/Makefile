SRC		= main.c ft_struct.c ft_print.c ft_split.c \
		ft_manage_str.c ft_open.c ft_check_error.c ft_check_error_sub.c \
		ft_solve_puzzle.c ft_solve_puzzle_sub.c ft_free.c ft_process_main.c

SRCDIR	= ./srcs/

SRCS	= $(addprefix $(SRCDIR), $(SRC))

OBJS	= ${SRCS:.c=.o}

INCS	= ./includes/

NAME	= bsq

CC		= cc

AR		= ar rc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I ${INCS}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
