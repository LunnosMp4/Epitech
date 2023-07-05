##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

.SILENT:

all: server client

server:
	@make -C ./src/server/

client:
	@make -C ./src/client/

clean:
	@make clean -C ./src/client/
	@make clean -C ./src/server/

fclean: clean
	@make fclean -C ./src/client/
	@make fclean -C ./src/server/

re: fclean all

.PHONY: all server client clean fclean re
