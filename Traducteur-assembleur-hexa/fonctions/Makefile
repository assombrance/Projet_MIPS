CC = gcc
FLAGS = -Wall -ansi -pedantic
EXE = test
FONCTION = add

$(EXE): main.o $(FONCTION).o
	$(CC) -o $(EXE) main.o $(FONCTION).o

../../decimalToBinary.o : decimalToBinary.c Convertion.h
	$(CC) -c decimalToBinary $(FLAGS) decimalToBinary.o

../../binaryToHexa.o : binaryToHexa.c Convertion.h
	$(CC) -c binaryToHexa $(FLAGS) binaryToHexa.o

$(FONCTION).o: $(FONCTION).c fonctionsHexa.h
	$(CC) -c $(FONCTION).c $(FLAGS) -o $(FONCTION).o

main.o: main.c
	$(CC) -c main.c $(FLAGS) -o main.o

clean:
	rm -f *.o