main: main.c main.h clean.c clean.h data.c data.h
	gcc -o clean main.c main.h clean.c clean.h data.c data.h
delete:
	rm -f clean