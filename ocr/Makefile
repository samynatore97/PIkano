CC = gcc

CPPFLAGS = `pkg-config --cflags sdl`
CFLAGS = -Wall -Wextra  -std=c99 -O0 -g -pedantic
LDFLAGS =
LDLIBS = `pkg-config --libs sdl` -lSDL_image

SRC =		matrix.c \
		pixel_operations.c \
		ligne_iden.c \
		SDL_init.c \
		list.c \
		graph_iden.c  \
		surface_operations.c \
		coord.c		\
		portee.c 	\
		detection/cle_de_sol.c \
		main.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}
all: main

-include ${DEP}

main: ${OBJ}

clean:
	 rm -f ${OBJ} ${DEP} main

# END

