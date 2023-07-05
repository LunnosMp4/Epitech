##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC	=	@gcc

CFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system \
		-lcsfml-audio -I./include/

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

TARGET	=	my_runner

all:	$(TARGET)

$(TARGET):	$(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS)
clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(TARGET)

re:	fclean all
