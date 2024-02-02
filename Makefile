all:
	gcc -o Hamil main.c func-proc.c
dbg :
	gcc -g -o debug main.c func-proc.c
	gdb debug