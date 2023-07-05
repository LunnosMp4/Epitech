##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC 			= 	gcc

SRC 		=	$(wildcard src/*.c) \
				$(wildcard src/commands/*.c) \
				$(wildcard src/commands/ai/*.c) \
				$(wildcard src/commands/gui/*.c) \
				$(wildcard src/commands/select/*.c) \
				$(wildcard src/error_handling/*.c) \
				$(wildcard src/network/client/*.c) \
				$(wildcard src/network/server/*.c) \
				$(wildcard src/parsing/*.c) \
				$(wildcard src/utils/*.c)

OBJ 		= 	$(SRC:.c=.o)

BIN			= 	zappy_server

CFLAGS		= 	-W -Wall -Wextra -Werror -g3

CPPFLAGS 	= 	-I./include

LDFLAGS 	= 	-lm -lrt

all: $(BIN)

$(BIN) : $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(BIN)

re : fclean all
