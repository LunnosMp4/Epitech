##
## EPITECH PROJECT, 2022
## B-OOP-400-MPL-4-1-arcade-loic.tisseyre
## File description:
## Makefile
##

.SILENT:

all:
	@make -C ./nCurses
	@make -C ./SDL2
	@make -C ./SFML
	@make -C ./Allegro

clean:
	@make clean -C ./nCurses
	@make clean -C ./SDL2
	@make clean -C ./SFML
	@make clean -C ./Allegro

fclean: clean
	@make fclean -C ./nCurses
	@make fclean -C ./SDL2
	@make fclean -C ./SFML
	@make fclean -C ./Allegro

re: fclean all
