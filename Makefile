#test shared library 

LIB_PATH=.


main: main.o libtest.so
	gcc $(CFLAGS) -o main main.o -L${LIB_PATH} -ldl -ltest -Wl,-rpath=.


main.o: main.c test.h
	gcc $(CFLAGS) -c main.c


test.o: test.c
	gcc -c -fPIC test.c

libtest.so: test.o
	gcc -shared -fPIC -o libtest.so test.o

clean:
	rm -f *.o main
