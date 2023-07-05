##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Wextra -Iinclude -g3

SRC 		=	$(wildcard src/*.c) \
				$(wildcard src/utils/*.c) \
				$(wildcard src/builtins/*.c) \
				$(wildcard src/builtins/env/*.c) \
				$(wildcard src/builtins/alias/*.c) \
				$(wildcard src/builtins/exec/*.c) \
				$(wildcard src/inhibitors/*.c) \
				$(wildcard src/tree/*.c) \
				$(wildcard src/ncurses/*.c) \
				$(wildcard src/builtins/globbing/*.c)

OSRC 		=	$(wildcard lib/my/*.c) \

OBJ 		= 	$(SRC:.c=.o)

TARGET		= 	42sh

NB_FILES := $(words $(SRC) $(OSRC))

.SILENT:	$(OBJ)

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@echo "\033[1;99m\n ❖ Compilation\033[0m\n ╥"
	@echo "\033[5;99m ╠ Files compiled \033[1;94m$(NB_FILES)\033[0m\n ║\033[0m"
	@echo "\033[1;99m ║  \033[1;94msrc/\033[0m\n ╠══╛\033[0m"
	@echo "\033[1;99m ║  \033[1;94mlib/my/\033[0m\n ╠══╛\033[0m"
	@echo "\033[1;99m ║  \033[1;94msrc/builtins/\033[0m\n ╚══╛\033[0m"

	@echo "\033[1;92m\n╔\033[0m"
	@make -C lib/my/ -s
	@$(CC) -o $(TARGET) $(OBJ) -Llib/my/ -lmy -lncurses
	@echo "\033[1;92m    BUILD   √\n\t\t╝\033[0m"

clean :
	@make clean -C lib/my/ -s
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C lib/my/ -s
	@rm -rf $(TARGET)

re : fclean all
