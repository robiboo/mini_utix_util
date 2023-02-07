.SUFFIXES: .c .o
CC = gcc
CCFLAGS = -Wall -Werror
EXEC = my-cat
OBJS = my-cat.o
EXEC2 = my-sed
OBJS2 = my-sed.o

${EXEC}: ${OBJS}
	${CC} ${CCFLAGS} -o ${EXEC} ${OBJS}

${EXEC2}: ${OBJS2}
	${CC} ${CCFLAGS} -o ${EXEC2} ${OBJS2}

.c.o:
	${CC} ${CCFLAGS} -c $<

run: ${EXEC} ${EXEC2}
	./${EXEC}
	./${EXEC2}

clean:
	rm -f ${EXEC} ${OBJS}
	rm -f ${EXEC2} ${OBJS2}

my-cat.o: my-cat.c
my-sed.o: my-sed.c