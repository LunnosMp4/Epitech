##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC			= 	gcc
CFLAGS		= 	-W -Wall -Wextra -I../../include
LDFLAGS		=	-L../../libs/myteams -Wl,-rpath=./libs/myteams
LDLIBS		= 	-lmyteams -luuid

SRC 		=	$(shell find ./ -name "*.c") \
				$(wildcard ../utils/*.c) \

OBJ 		= 	$(SRC:.c=.o)

TARGET		= 	../../myteams_server

NB_FILES := $(words $(SRC))

.SILENT:	$(OBJ)

all: $(TARGET)

$(TARGET): 	$(OBJ)
	@echo "\033[1;99m\n ❖ Compilation\033[0m\n ╥"
	@echo "\033[5;99m ╠ Files compiled \033[1;94m$(NB_FILES)\033[0m\n ║\033[0m"
	@echo "\033[1;99m ║  \033[1;94msrc/\033[0m\n ╚══╛\033[0m"

	@echo "\033[1;92m\n╔\033[0m"
	@$(CC) $(LDFLAGS) -o $(TARGET) $(OBJ) $(LDLIBS)
	@echo "\033[1;92m    BUILD   √\n\t\t╝\033[0m"

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(TARGET)

re : fclean all
