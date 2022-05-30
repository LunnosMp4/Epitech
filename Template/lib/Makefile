##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CFLAGS	=	-I../include/

SRC =	my_flags_cases.c \
	my_getnbr.c \
	my_getoctal.c \
	my_printf.c \
	my_put_nbr_unsigned.c \
	my_put_nbr_base.c \
	my_put_nbr_long.c \
	my_put_nbr.c \
	my_putchar.c \
	my_putcharc.c \
	my_putstrs.c \
	my_putstr.c \
	my_strlen.c

OBJ	=	$(SRC:.c=.o)

NBR_OF_FILES := $(words $(SRC))

TARGET	=	libmy.a

all:	$(TARGET)

$(TARGET):	$(OBJ)
	@ar rc $(TARGET) $(OBJ)
clean:
	@echo "\033[3;31m$(OBJ)\033[0m" | tr ' ' '\n'
	@rm -f $(OBJ)

fclean:	clean
	@echo "\033[3;31m./$(TARGET)\033[0m"
	@rm -f $(TARGET)

re:	fclean all
