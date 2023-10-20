CC = gcc

all: clean
	$(CC) main.c mybigint.c -o main
	./main

clean:
	rm -rf main result.txt