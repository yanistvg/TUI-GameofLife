PROGNAME=TUI-GameOfLife

CC=gcc
CFLAGS=-Wall -Wextra -Wconversion

OBJS= main.o              \
      interact-terminal.o \
	  game.o              \
	  parse.o

all: ${OBJS}
	${CC} ${CFLAGS} -o ${PROGNAME} ${OBJS}

main.o: main.c libs/headers/main.h
	${CC} ${CFLAGS} -c main.c
interact-terminal.o: libs/srcs/interact-terminal.c libs/headers/interact-terminal.h
	${CC} ${CFLAGS} -c libs/srcs/interact-terminal.c
game.o: libs/srcs/game.c libs/headers/game.h
	${CC} ${CFLAGS} -c libs/srcs/game.c
parse.o: libs/srcs/parse.c libs/headers/parse.h
	${CC} ${CFLAGS} -c libs/srcs/parse.c

clean:
	rm ${OBJS} ${PROGNAME}
