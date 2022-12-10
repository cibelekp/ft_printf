# Your must submit a Makefile which will compile a libftprintf.a. This lib will be
# linked to our testing main to give you your results

CC			= clang
CFLAGS		= -Wall -Werror -Wextra

NAME		= libftprintf.a
HEAD		= ft_printf.h
SOURCES		= ft_printf.c

OBJECTS		= ${SOURCES:.c=.o}
MKLIB		= ar -rcs
RM			= rm -rf
LIB_FILES	= ar -t

${NAME}: ${OBJECTS}
	${MKLIB} ${NAME} ${OBJECTS}
	
all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re