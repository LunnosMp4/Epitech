##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC	=	@gcc

CFLAGS	=	-W -Wall -Wextra -I../include/ -g3

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

TARGET	=	solver

all:	$(TARGET)

$(TARGET):	$(OBJ)
	@ $(CC) -o $(TARGET) $(OBJ)

clean:
	@ rm -f $(OBJ)

fclean:	clean
	@ rm -f $(TARGET)

re:	fclean all
