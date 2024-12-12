SRCS = ft_printf.c \
	ft_printf_char.c \
	ft_printf_hex.c \
	ft_printf_int.c \
	ft_printf_percent.c \
	ft_printf_ptr.c \
	ft_printf_str.c \
	ft_printf_unsigned.c \
	ft_itoa.c \
	test.c \
	test_write.c \
	support_ft.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c libft.h
		${CC} ${CFLAGS} -I. -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
