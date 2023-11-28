PUSH SWAP

da consegnare: makefile, *.h, *.c
il make deve compilare UN PROGRAMMA

CONTROLLO INPUT
	- controllo COSA ricevo in input:
		se non numeric	Error\n; 									ok
		se non int	Error\n; 										ok
		se duplicati	Error\n; 									ok
			da restituire su STDERROR (fd = 2) 						~incompleta
		se nessun parametro, non stampare nulla e attendere input.	ok
		gestione MAXINT e MININT;									ok
		se stack gia' ordinato, terminare							tpicchio
		se size di stack < 2 terminare
		se input valido, stampare OK e procedere

COPIARE STACK (CSTACK)
	- utilizzare struct da inserire in lista libft (content);
		in struct indice e numero
	- ordinare lista con metodo LIS;
		registrare mosse;
		se mosse nei limiti, restituire mosse;
-----------------------------------------------
ORDINARE CSTACK
	- se lista mosse presente
		split con sep \n
		applicare mosse
		stampare mosse
 ----------------------------------------------
VERIFICARE MOSSE
	se size 3	risolvere in 1    o meno sort1
	se {1 5 2 4 3}	risolvere in 8    o meno SORT2
	se size 5	risolvere in 12   o meno SORT2
	se size 100	risolvere in 700  o meno LIS
	se size 500	risolvere in 5500 o meno LIS

ORDINARE STACK


ricevo argv
parsing
inserisco in lista
setto la lista a 0
passo la lista
	settare index
	settare swap (in dist)
	calcolo liis
		montaggio stringa mosse
			set stacks


