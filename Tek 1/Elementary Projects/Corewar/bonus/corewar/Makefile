##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC	=	 @gcc

CFLAGS	=	-W -Wall -Wextra -g3

CPPFLAGS	=	-I../include/

SRC	=	$(wildcard src/*.c) \
		$(wildcard src/linked_list/*.c) \
		$(wildcard src/instruction/*.c) \
		$(wildcard src/utils/*.c)

OBJ	=	$(SRC:.c=.o)

TARGET	= corewar

all:	$(TARGET)

$(TARGET):	$(OBJ)
	@ make -C ../lib/my/
	@ $(CC) -o $(TARGET) $(OBJ) -L../lib/my/ -lmy
clean:
	@ make clean -C ../lib/my/
	@ rm -f $(OBJ)

fclean:	clean
	@ make fclean -C ../lib/my/
	@ rm -f $(TARGET)

re:	fclean all
