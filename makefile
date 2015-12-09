CFLAGS=-Wall 
OBJ=main.o affichage.o move.o sur.o tech.o

snake:$(OBJ)
	gcc -o snake $(OBJ) $(CFLAGS)

affichage.o:./source/affichage.c ./source/affichage.h ./source/move.h ./source/sur.h ./source/tech.h ./source/coor.h
	gcc -c ./source/affichage.c $(CFLAGS)

move.o:./source/move.c ./source/move.h ./source/tech.h ./source/coor.h 
	gcc -c ./source/move.c $(CFLAGS)

sur.o:./source/sur.c ./source/sur.h ./source/coor.h
	gcc -c ./source/sur.c $(CFLAGS)

tech.o:./source/tech.c ./source/tech.h
	gcc -c ./source/tech.c $(CFLAGS)

main.o:./source/main.c ./source/affichage.h
	gcc -c ./source/main.c $(CFLAGS)

clean:
	rm snake
	rm *.o