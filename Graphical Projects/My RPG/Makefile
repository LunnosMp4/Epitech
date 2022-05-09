##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Wextra -Wimplicit-fallthrough=0 -g3
CPPFLAGS	=	-Iinclude/
LDFLAGS		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC 		=	$(wildcard src/*.c) \
				$(wildcard src/game/*.c) \
				$(wildcard src/game/init_game/*.c) \
				$(wildcard src/game/process/*.c) \
				$(wildcard src/game/process/ingame/*.c) \
				$(wildcard src/game/process/ingame/gui/*.c) \
				$(wildcard src/game/process/ingame/poutine/*.c) \
				$(wildcard src/game/ingame/*.c) \
				$(wildcard src/game/ingame/animation/*.c) \
				$(wildcard src/game/ingame/event/*.c) \
				$(wildcard src/game/ingame/init_maps/*.c) \
				$(wildcard src/game/menu/*.c) \
				$(wildcard src/game/menu/create/*.c) \
				$(wildcard src/utils/*.c) \
				$(wildcard src/utils/create_object/*.c) \
				$(wildcard src/utils/save_stat/*.c)

OBJ 		= 	$(SRC:.c=.o)

TARGET		= 	my_rpg

.SILENT: $(OBJ)

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@echo "\033[1;93mCompilation du src...\033[0m"
	@make -C lib/my/ -s
	@$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS) -Llib/my/ -lmy
	@echo "\033[1;92mBuild OK!\033[0m"

clean :
	@make clean -C lib/my/ -s
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C lib/my/ -s
	@rm -rf $(TARGET)

re : fclean all
