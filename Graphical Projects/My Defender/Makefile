##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Wextra
CPPFLAGS	=	-Iinclude/
LDFLAGS		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC 		=	$(wildcard src/*.c) \
				$(wildcard src/event/*.c) \
				$(wildcard src/event/ingame/*.c) \
				$(wildcard src/ingame/*.c) \
				$(wildcard src/ingame/init/*.c) \
				$(wildcard src/process/*.c) \
				$(wildcard src/process/ingame/*.c) \
				$(wildcard src/utils/*.c) \
				$(wildcard src/map/*.c) \
				$(wildcard src/menu/*.c)

OBJ 		= 	$(SRC:.c=.o)

TARGET		= 	my_defender

.SILENT: $(OBJ)

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@echo "\033[1;93mCompilation du src...\033[0m"
	@$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)
	@echo "\033[1;92mBuild OK!\033[0m"

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(TARGET)

re : fclean all
