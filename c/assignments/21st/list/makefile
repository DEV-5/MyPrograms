
project: main.o print.o add.o del.o save.o syncdata.o
	gcc -o project print.o main.o add.o del.o save.o syncdata.o
add.o: add.c
	gcc -c add.c -o add.o
del.o: del.c
	gcc -c del.c -o del.o
print.o: print.c
	gcc -c print.c -o print.o
main.o: main.c
	gcc -c main.c -o main.o	
save.o: save.c 	
	gcc -c save.c -o save.o
syncdata.o: syncdata.c 	
	gcc -c syncdata.c -o syncdata.o
