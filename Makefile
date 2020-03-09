all:	
	clear && gcc main.c -o ./exec
leak:
	clear && gcc main.c -o exec && valgrind --leak-check=yes ./exec
debug:
	gcc main.c -g
run:
	clear && ./exec