CC = gcc
# CFLAGS = -Werror -Wextra -Wall
CRUNFILE = ./app

all: clean
	mkdir -p results
	$(CC) $(CFLAGS) main.c mybigint.c -o $(CRUNFILE) -lgmp

run:
	$(CRUNFILE)

install:
	sudo apt-get install libgmp3-dev

clean:
	rm -rf $(CRUNFILE) ./results