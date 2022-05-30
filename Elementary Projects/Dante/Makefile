##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

all:
	@ echo "\e[32;1m✔ \e[1;32mMaze generator and solver created successfully !"
	@ make -C generator/ --no-print-directory
	@ make -C solver/ --no-print-directory
clean:
	@ echo "\e[32;1m✔ \e[1;31mClean .o successfully !"
	@ make clean -C generator/ --no-print-directory
	@ make clean -C solver/ --no-print-directory

fclean:	clean
	@ echo "\e[32;1m✔ \e[1;31mClean binary successfully !"
	@ make fclean -C generator/ --no-print-directory
	@ make fclean -C solver/ --no-print-directory

re:	fclean all
