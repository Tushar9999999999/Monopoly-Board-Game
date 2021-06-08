a: monopoly.o func.o property.o jail.o dice.o gamestate.o cards.o
	gcc monopoly.o func.o property.o jail.o dice.o gamestate.o cards.o -o a

monopoly.o: monopoly.c head.h
	gcc -c monopoly.c

func.o: func.c head.h
	gcc -c func.c

property.o: property.c head.h
	gcc -c property.c

jail.o: jail.c head.h
	gcc -c jail.c

dice.o: dice.c head.h
	gcc -c dice.c

gamestate.o: gamestate.c head.h
	gcc -c gamestate.c

cards.o: cards.c head.h
	gcc -c cards.c

clear: 
	del monopoly.o func.o property.o a.exe