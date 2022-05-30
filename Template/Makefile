##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC	=	gcc

CFLAGS	=	-I./include/

MYLIB   =	-L./lib/ -lmy

SRC	= $(wildcard src/*.c) \

OBJ	=	$(SRC:.c=.o)

NBR_OF_FILES := $(words $(SRC))

TARGET	=	name

all:	$(TARGET)

$(TARGET):	$(OBJ)
	@echo "\033[1;36m[FILES COMPILED] \033[0m \033[1;34m$(NBR_OF_FILES)\033[0m"
	@make -C lib/ --no-print-directory
	@$(CC) -o $(TARGET) $(OBJ) $(MYLIB) $(CFLAGS)

clean:
	@echo "\033[3;31mRemoving: \033[0m"
	@echo "\033[3;31m$(OBJ)\033[0m" | tr ' ' '\n\n'
	@make clean -C lib/ --no-print-directory
	@rm -f $(OBJ)

fclean:	clean
	@echo "\033[3;31m./$(TARGET)\033[0m"
	@make fclean -C lib/ --no-print-directory
	@rm -f $(TARGET)

re:	fclean all
