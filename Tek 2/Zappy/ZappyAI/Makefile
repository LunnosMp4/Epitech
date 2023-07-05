##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC			= 	g++

INCLUDE_SOURCE		=	include src src/Network src/Core src/AI

FILES_SOURCE =

INCLUDE_PATHS		=	$(foreach folder, $(INCLUDE_SOURCE), -I./$(folder))

CPPFLAGS		= 	-std=c++2a -Wall -Wextra -Werror -lpthread $(INCLUDE_PATHS)

SRC 		=	$(shell find -name "*.cpp")

OBJ 		= 	$(SRC:.cpp=.o)

TARGET		= 	zappy_ai

NB_FILES	:=	$(words $(SRC))

.SILENT:	$(OBJ)

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@echo "\033[1;99m\n ❖ Compilation\033[0m\n ╥"
	@echo "\033[5;99m ╠ Files compiled \033[1;94m$(NB_FILES)\033[0m\n ║\033[0m"
	@echo "\033[1;99m ║  \033[1;94msrc/\033[0m\n ╚══╛\033[0m"

	@echo "\033[1;92m\n╔\033[0m"
	@$(CC) -o $(TARGET) $(OBJ) $(CPPFLAGS)
	@echo "\033[1;92m    BUILD   √\n\t\t╝\033[0m"

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(TARGET)

re : fclean all
