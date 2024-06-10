PROGNAME=TUI-GameOfLife

CC=gcc
CFLAGS=-Wall -Wextra -Wconversion

OBJS= main.o              \
      interact-terminal.o \
	  game.o              \
	  parse.o             \
	  show_game.o         \
	  draw_utils.o        \
	  interact-file.o

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
show_game.o: libs/srcs/show_game.c libs/headers/show_game.h
	${CC} ${CFLAGS} -c libs/srcs/show_game.c
draw_utils.o: libs/srcs/draw_utils.c libs/headers/draw_utils.h
	${CC} ${CFLAGS} -c libs/srcs/draw_utils.c
interact-file.o: libs/srcs/interact-file.c libs/headers/interact-file.h
	${CC} ${CFLAGS} -c libs/srcs/interact-file.c

clean:
	rm ${OBJS} ${PROGNAME}
