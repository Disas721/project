CC=gcc
CFLAGS= -Wall -g -fprofile-arcs -ftest-coverage

all: tests
tests.o: tests.c
	${CC} -c tests.c -o tests.o ${CFLAGS}
stack.o: queue.c
	${CC} -c queue.c -o queue.o ${CFLAGS}
tests: tests.o queue.o
	${CC} queue.o tests.o -o tests ${CFLAGS}
clean:
	@rm -rf *.o *.gcno *.gcda *.gcov tests 2&>/dev/null
tar:
	tar czvf ../queue.tgz ../queue