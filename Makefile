NAME	= libftprintf.a

SRC = ft_printf.c b_files/ft_printf_bonus.c b_files/ft_printf_bonus_utils.c ft_putchar.c b_files/ft_flags.c b_files/ft_flags1.c

OBJ	= ${SRC:.c=.o}

INC = ft_printf.h

.PHONY: all clean fclean re

all:	${NAME}

${NAME}: ${OBJ}
	@ar rc $@ $^

bonus : all

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -I ${INC} -o $@

clean:
	@rm -f ${OBJ} ${OBJB}

fclean:
	@rm -f ${OBJ} ${NAME} ${OBJB}

re: fclean bonus
