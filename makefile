all: main.o linked_list.o library.o
	gcc -o tunez main.o linked_list.o library.o

library.o: library.c library.h
	gcc -c library.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

main.o: main.c
	gcc -c main.c

run:
	./tunez

clean:
	rm *.o
