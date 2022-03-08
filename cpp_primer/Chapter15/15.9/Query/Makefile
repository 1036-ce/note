CC=g++

main: TextQuery.o Query.o main.o
	$(CC) -g -o main main.o TextQuery.o Query.o
main.o: main.cpp TextQuery.h Query.h
	$(CC) -g -c main.cpp
TextQuery.o: TextQuery.cpp TextQuery.h
	$(CC) -g -c TextQuery.cpp
Query.o: Query.cpp Query.h TextQuery.h
	$(CC) -g -c Query.cpp

clean:
	rm *.o
