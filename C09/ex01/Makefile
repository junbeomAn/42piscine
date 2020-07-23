DIR_SRC	= srcs

DIR_HEAD = includes

CFLAGS	= -Wall -Werror -Wextra

CC		= gcc

RM		= rm -f

CFILES	= $(DIR_SRC)/ft_putchar.c $(DIR_SRC)/ft_swap.c $(DIR_SRC)/ft_putstr.c $(DIR_SRC)/ft_strlen.c $(DIR_SRC)/ft_strcmp.c

OBJS	= $(CFILES:.c=.o)

TARGET	= libft.a

all:		$(TARGET)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $@ -I$(DIR_HEAD)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(TARGET)

re:			fclean all

${TARGET}:	$(OBJS)
			ar cr $@ $(OBJS)
