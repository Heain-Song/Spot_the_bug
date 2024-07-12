NAME	= tester

SRCS	= main.c\
		ft_putnbr_fd.c\
		ft_putchar_fd.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_strlen.c\


OBJS	= ${SRCS:.c=.o}

CC	= gcc

RM	= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean	all

.PHONY:		all clean fclean re
