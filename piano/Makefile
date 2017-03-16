## Simple SDL mini code
 
CC=gcc
 
CPPFLAGS= `pkg-config --cflags sdl`
CFLAGS= -Wall -Wextra -Werror -g -std=c99 -O0
LDFLAGS=
LDLIBS= `pkg-config --libs sdl` -lSDL_image -lSDL_ttf -lSDL_mixer -lm
 
SRC= main.c
OBJ= ${SRC:.c=.o}
 
all: main

main: $(OBJ)
 
clean:
	rm -f *~ *.o
	rm -f main
 
# END
