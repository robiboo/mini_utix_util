.SUFFIXES: .c .o
CC = gcc
CCFLAGS = -Wall -Werror
EXEC_CAT = my-cat
OBJS_CAT = my-cat.o
EXEC_SED = my-sed
OBJS_SED = my-sed.o
EXEC_UNIQ = my-uniq
OBJS_UNIQ = my-uniq.o

${EXEC_CAT}: ${OBJS_CAT}
	${CC} ${CCFLAGS} -o ${EXEC_CAT} ${OBJS_CAT}

${EXEC_SED}: ${OBJS_SED}
	${CC} ${CCFLAGS} -o ${EXEC_SED} ${OBJS_SED}

${EXEC_UNIQ}: ${OBJS_UNIQ}
	${CC} ${CCFLAGS} -o ${EXEC_UNIQ} ${OBJS_UNIQ}

.c.o:
	${CC} ${CCFLAGS} -c $<

run: ${EXEC_CAT} ${EXEC_SED} ${EXEC_UNIQ}
	./${EXEC_CAT}
	./${EXEC_SED}
	./${EXEC_UNIQ}

clean:
	rm -f ${EXEC_CAT} ${OBJS_CAT}
	rm -f ${EXEC_SED} ${OBJS_SED}
	rm -f ${EXEC_UNIQ} ${OBJS_UNIQ}

my-cat.o: my-cat.c
my-sed.o: my-sed.c
my-uniq.o: my-uniq.c