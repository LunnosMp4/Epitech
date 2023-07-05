##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

.SILENT:

all: core graphicals games
	@echo -e "\033[1;32m\n[Compilation Done]\033[0m"

core:
	@make -C ./core/

graphicals:
	@make -C ./graphicals/

games:
	@make -C ./games/

clean:
	@make clean -C ./graphicals/
	@make clean -C ./games/
	@make clean -C ./core/

fclean: clean
	@make fclean -C ./graphicals/
	@make fclean -C ./games/
	@make fclean -C ./core/
	@echo -e "\033[1;31m\n[Clean Done]\033[0m"

re: fclean all

.PHONY: all core graphicals games clean fclean re