##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC = gcc -g3
CFLAGS = -W -Wall -Wextra -Werror
CPPFLAGS = -I../include

SRC	= $(wildcard src/*.c) \
	  $(wildcard src/instructions/*.c) \
	  $(wildcard src/prog_size/*.c) \

OBJ	= $(SRC:.c=.o)

TARGET = asm

all: $(TARGET)

$(TARGET): $(OBJ)
	@ make -C ../lib/my/ libmy.a
	@ $(CC) -o $(TARGET) $(OBJ) -L../lib/my/ -lmy
clean:
	@ make clean -C ../lib/my/
	@ rm -f $(OBJ)

fclean:	clean
	@ make fclean -C ../lib/my
	@ rm -f $(TARGET)

re:	fclean all
