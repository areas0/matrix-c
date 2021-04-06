CC= gcc #-fsanitize=address
CFLAGS= -lmath -Wall -Wextra -Werror -std=c99 -O3 -g2
LDFLAGS =
LDLIBS =

SRC = ./tools/matrix.c ./tools/operations.c ./main.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: main

main: ${OBJ}

.PHONY: clean

clean:
	${RM} ${OBJ}   # remove object files
	${RM} ${DEP}   # remove dependency files
	${RM} main     # remove main program

-include ${DEP}