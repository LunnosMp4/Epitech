##
## EPITECH PROJECT, 2022
## Visual Studio Live Share (Workspace)
## File description:
## Makefile
##

.SILENT:

SRC		=	$(wildcard ./*.cpp)

CPPFLAGS	=	-I./ -I../graphicals -I../games -W -Wall -Wextra -g -std=c++17 -rdynamic

LIBFLAGS	=	-ldl

OBJ		=	$(SRC:.cpp=.o)

NAME		=	arcade

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ -o ../$(NAME) $(OBJ) $(CPPFLAGS) $(LIBFLAGS)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) ../$(NAME)

re:	fclean all