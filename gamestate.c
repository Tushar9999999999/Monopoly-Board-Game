#include "head.h"

//Game State
void game_state(int nGame)
{
	int nplayers = nGame, option;
	bool error;

	printf("1 - Status of each player\n");
	printf("2 - State of the board\n");
	do
	{
		error = false;
		scanf("%d", &option);
		switch (option)
		{
			//General status of the game organized by Player
			case 1:
				for (int i = 0; i < nplayers; i++)
				{
					printf("\n========== Player %d - %s ==========\n", i + 1, players[i].name);
					printf(" * balance       : M%d\n", players[i].balance);
					printf(" * position      : House %d - %s\n", players[i].position, property[players[i].position].name);
					printf(" * property :\n");
					for (int j = 0; j < 40; j++)
					{
						if (strcmp(property[j].owner, players[i].name) == 0)
						{
							printf("    * %s\n", property[j].name);
						}
					}
					printf("\n=======================================\n");
				}
				break;

			//General state of the game organized by board
			case 2:
				printf("\n=============== Board ===============\n");
				for (int i = 0; i < 40; i++)
				{
					if (i == 10 || i == 20 || i == 30)
						printf("\n\n");
					printf("\n * %2d - %s\n", i, property[i].name);
					if (strcmp(property[i].owner, "Prohibited") == 0)
						printf("\n");
					else
					{
						printf("        owner : %s\n", property[i].owner);
						if (strcmp(property[i].owner, "no owner") == 0)
							printf("\n");
						else
						{
							if (property[i].nhouses == 5)
							{	
								printf("        HOUSES       : 4\n");
								printf("        HOTEL        : 1\n");
							}
							else
							{
								printf("        HOUSES       : %d\n", property[i].nhouses);
								printf("        HOTEL        : 0\n");
							}
							if (property[i].mortgage == true)
							{
								printf("        Mortgaged   : Yes\n");
							}
							else
								printf("        Mortgaged   : No\n");	
						}
					}
				}
				printf("\n=========================================\n");
				break;

			//option Invalid
			default:
				printf("Error! Enter a valid option: \n");
				error = true;
				break;
		}
	} while (error == true);
}