all:	
	clear && gcc sources/floodfill.c sources/criptografia.c main.c -o ./exec
leak:
	clear && gcc sources/floodfill.c sources/criptografia.c main.c -o exec && valgrind --leak-check=yes ./exec
run:
	clear && ./exec