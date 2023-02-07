.SUFFIXES: .c .o
CC = gcc
CCFLAGS = -Wall -Werror
EXEC = my-cat
OBJS = my-cat.o

${EXEC}: ${OBJS}
	${CC} ${CCFLAGS} -o ${EXEC} ${OBJS}

.c.o:
	${CC} ${CCFLAGS} -c $<

run: ${EXEC}
	./${EXEC}

clean:
	rm -f ${EXEC} ${OBJS}

my-cat.o: my-cat.c