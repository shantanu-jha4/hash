all: hash_run

hash_run: hash.c main.c hash.h
	gcc -Wall -Werror -g -o hash_run main.c hash.c 
