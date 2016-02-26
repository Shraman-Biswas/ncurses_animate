all:
	gcc -Wall main.c -o main -lncurses

clean:
	rm -rf *~ *o main
