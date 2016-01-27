FLAGS = -Wall -pedantic
FONCTION = addi.c add.c and.c div.c lui.c lw.c mfhi.c mflo.c mult.c or.c rotr.c sll.c slt.c srl.c sub.c sw.c xor.c \
j.c jr.c jal.c blez.c beq.c bne.c bgtz.c
UTILITAIRE = miseEnForme.c taille.c convMnemoniqueEmul.c

test: main.o $(FONCTION:.c=.o) $(UTILITAIRE:.c=.o)
	gcc -o test main.o $(FONCTION:.c=.o) $(UTILITAIRE:.c=.o)

$(FONCTION:.c=.o): $(FONCTION)
	gcc -c $(FONCTION) $(FLAGS)

$(UTILITAIRE:.c=.o): $(UTILITAIRE)
	gcc -c $(UTILITAIRE) $(FLAGS)

main.o: main.c
	gcc -c main.c $(FLAGS)

clean:
	rm -f *.o

cleana:
	rm -f *.o test