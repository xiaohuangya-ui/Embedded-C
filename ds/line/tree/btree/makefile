all : main

main : main.o btree.o sqlist.o queue.o
	$(CC) $^ -o $@

clean :
	rm -rf *.o main

