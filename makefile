main:main.o fun1.o my.h
	gcc main.o fun1.o my.h -o main
main.o:main.c
	gcc main.c -c
fun1.o:fun1.c
	gcc fun1.c -c
clean:
	rm -f *.o
