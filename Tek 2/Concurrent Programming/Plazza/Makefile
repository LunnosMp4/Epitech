##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC			= 	g++

CFLAGS		= 	-g -std=c++2a -Wall -Wextra -Werror -lpthread -I./include -I./src -I./src/ingredients

SRC 		=	$(shell find -name "*.cpp")

OBJ 		= 	$(SRC:.cpp=.o)

DEP 		=	$(OBJ:.o=.d)

TARGET		= 	plazza

NB_FILES	:=	$(words $(SRC))

.SILENT:	$(OBJ)

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@echo "\033[1;99m\n ❖ Compilation\033[0m\n ╥"
	@echo "\033[5;99m ╠ Files compiled \033[1;94m$(NB_FILES)\033[0m\n ║\033[0m"
	@echo "\033[1;99m ║  \033[1;94msrc/\033[0m\n ╚══╛\033[0m"

	@echo "\033[1;92m\n╔\033[0m"
	@$(CC) $^ -o $@ $(LDFLAGS)
	@echo "\033[1;92m    BUILD   √\n\t\t╝\033[0m"

-include $(DEP)

%.o: %.cpp
	@$(CC) -c $< -o $@ $(CFLAGS)
	@$(CC) -MM $< -MT $@ -MF $(@:.o=.d) $(CFLAGS)

clean :
	@$(RM) $(OBJ) $(DEP)

fclean : clean
	@rm -rf $(TARGET)

re : fclean all
