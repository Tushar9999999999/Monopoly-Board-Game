#include "head.h"

//Jail
void jail(int play)
{
	int i=play;

	if (players[i].jail==-1)
	{
		printf("Free pass used\n");
		players[i].jail=0;
		printf("\nCurrent Position = House %d - %s\n", players[i].position, property[players[i].position].name);
	}
	else if(players[i].jail==0)
	{
		players[i].position=10;
		players[i].jail=1;
		printf("\nCurrent Position = House %d - JAIL\n", players[i].position);
	}
	else if (players[i].jail==1)
	{
		printf("You need to roll a double to get out of jail.\n");
		int dice1, dice2;

		dice1 = (rand() % 6) + 1;
		dice2 = (rand() % 6) + 1;

		printf(" * The roll: %d + %d = %d\n", dice1, dice2, dice1 + dice2);

		if (dice1 == dice2)
		{
			printf("Got out of jail!");
			players[i].jail=0;
		}
		else 
			printf("Stuck in Jail\n");
	}
}