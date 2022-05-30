##
## EPITECH PROJECT, 2021
## Lib My
## File description:
## Makefile
##

CC			=	gcc

LIB_SRC		= 	$(wildcard *.c) \
				$(wildcard math/*.c) \
				$(wildcard print/*.c) \
				$(wildcard utils/*.c) \

LIB_OBJ 	= 	$(LIB_SRC:.c=.o)

CPPFLAGS = -I../../include
CFLAGS	=	-W -Wall -Wextra -Werror -g3

TARGET_LIB	= 	libmy.a

.SILENT:	$(OBJ)

all: $(TARGET_LIB)

$(TARGET_LIB):	$(LIB_OBJ)
	@ar src $(TARGET_LIB) $(LIB_OBJ)
	@echo "\033[1;92m    LIB     √\033[0m"

clean:
	@rm -rf $(LIB_OBJ)

fclean: clean
	@rm -rf $(TARGET_LIB)

re : fclean all
