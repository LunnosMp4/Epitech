##
## EPITECH PROJECT, 2022
## Visual Studio Live Share (Workspace)
## File description:
## Makefile
##

.SILENT:

CC 		= 	g++
RM 		= 	rm -f
TARGET_LIB 	= 	arcade_allegro5.so

SRCS	= 	$(wildcard *.cpp)

OBJS	= 	$(SRCS:.cpp=.o)

CPPFLAGS	=	-I. -I../../core
CPPFLAGS	+=	-W -Wall -Wextra -fPIC -rdynamic -std=c++11
LDFLAGS	=	-shared -lallegro -lallegro_image -lallegro_ttf -lallegro_primitives -lallegro_font

all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS)
	@mkdir -p ../../lib
	@$(CC) $(OBJS) -o ../../lib/$(TARGET_LIB) $(LDFLAGS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) ../../lib/$(TARGET_LIB)

re: fclean all
