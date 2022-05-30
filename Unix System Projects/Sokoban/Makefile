##
## EPITECH PROJECT, 2021
## B-PSU-200-MPL-2-1-mysokoban-loic.tisseyre
## File description:
## Makefile
##

CC      =       gcc

CPPFLAGS = 	-I./includes

CFLAGS  =       -W -Wall -Wextra

SRC     =       $(wildcard src/*.c) \
		$(wildcard src/player_movement/*.c)

OBJ     =       $(SRC:.c=.o)

TARGET  =       my_sokoban

all:    $(TARGET)


$(TARGET):      $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) -lncurses
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re:     fclean all