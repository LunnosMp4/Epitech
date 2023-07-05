##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC			=	 @gcc

CFLAGS		=	-W -Wall -Wextra -g3

CPPFLAGS	=	-I./include/

LDFLAGS		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC	=	$(wildcard corewar/src/*.c) \
		$(wildcard corewar/src/linked_list/*.c) \
		$(wildcard corewar/src/instruction/*.c) \
		$(wildcard corewar/src/utils/*.c) \
		$(wildcard graphic/src/*.c) \
		$(wildcard graphic/src/game/*.c) \
		$(wildcard graphic/src/game/init/*.c) \
		$(wildcard graphic/src/game/event/*.c) \
		$(wildcard graphic/src/utils/*.c)

OBJ	=	$(SRC:.c=.o)

TARGET	= bonus_corewar

all:	$(TARGET)

$(TARGET):	$(OBJ)
	@ make -C ../lib/my/
	@ $(CC) -o $(TARGET) $(OBJ) $(LDFLAGS) -L../lib/my/ -lmy
clean:
	@ make clean -C ../lib/my/
	@ rm -f $(OBJ)

fclean:	clean
	@ make fclean -C ../lib/my/
	@ rm -f $(TARGET)

re:	fclean all
