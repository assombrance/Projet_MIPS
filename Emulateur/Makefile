FLAGS = -Wall -pedantic
FONCTION = addi.c add.c and.c div.c lui.c lw.c mfhi.c mflo.c mult.c or.c rotr.c sll.c slt.c srl.c sub.c sw.c xor.c

test: main.o $(FONCTION:.c=.o)
	gcc -o test main.o $(FONCTION:.c=.o)

$(FONCTION:.c=.o): $(FONCTION)
	gcc -c $(FONCTION) $(FLAGS)

main.o: main.c
	gcc -c main.c $(FLAGS)

clean:
	rm -f *.o