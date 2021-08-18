Monopoly: main.o mode.o intro.o player.o
	gcc main.o mode.o intro.o player.o -o Monopoly

main.o: main.c game.h
	gcc -c main.c

mode.o: mode.c game.h
	gcc -c mode.c
	
intro.o: intro.c game.h
	gcc -c intro.c
	
player.o: player.c game.h
	gcc -c player.c
	