#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "head.h"

int main()
{
	system("cls");

	srand(time(NULL));
		
	initialize_board();
	cardsSelector();

	//Beginning of the game
	printf("|================================|============|================================|\n");
	printf("|========*=======*=======*=======|  MONOPOLY  |========*=======*=======*=======|\n");
	printf("|================================|============|================================|\n");
	printf("\nWelcome to Monopoly\n\n");

	//Game Home Menu
	menu:
	switch (menu())
	{
		case 1: goto newGame;
				break;
		case 2:
				printf("This game was coded in C language\n");
				printf("Developers: Tushar, Sahith and Vidip\n");
				fflush(stdin);
				getchar();
				goto menu;
				break;
	}

	//Starting a New Game
	newGame: 

	//Player selection
	printf("\n======================= Player selection =======================\n");
	int nplayers = playerSelection();
	printf("\n====================================================================\n");
	fflush(stdin);
	getchar();
	system("cls");

	int turn = 1;
	//Execution of turns
	do
	{
		if (turn==1)
		{
			for (int i=0; i<nplayers; i++)
				players[i].jail=0;
		}

		for (int i = 0; i < nplayers; i++)
		{
			printf("\n================================= Turn %3d =================================\n", turn);
			printf("\n========== Player %d - %s ==========\n", i + 1, players[i].name);
			printf(" * balance   : M%d \n", players[i].balance);
			printf(" * position : House %d - %s\n", players[i].position, property[players[i].position].name);
			printf("\n=======================================\n");

			//Data entry and calculation of the player's new position
			printf("\nRolling the dice...");
			getchar();

			int oldposition = players[i].position;
			players[i].position = newposition(players[i].position, dice(i));

			//Check if the Player is in or has passed through GO
			if ((players[i].position == 0) || (players[i].position < oldposition))
			{
				printf("\n Passed by GO. Receive M200.\n");
				players[i].balance += 200;
				printf("\nCurrent Balance : M%d\n", players[i].balance);
			}
			printf("\nCurrent Position = House %d - %s\n", players[i].position, property[players[i].position].name);

			//Details of the house the Player is in
			if (property[players[i].position].price != 0)
			{
				printf("\n             Property           \n");
				printf(" __________________________________\n");
				printf(" |                                |\n");
				printf(" | %-30.30s |   * owner : %s\n", property[players[i].position].name, property[players[i].position].owner);
				printf(" |                                |   * HOUSES      : %d\n", property[players[i].position].nhouses);
				printf(" |  color %-11.11s   price $%3d|   * HOTEL       : %d\n", property[players[i].position].color, property[players[i].position].price, property[players[i].position].nhouses);
				printf(" | ------------------------------ |\n");
				printf(" |             rent               |\n");
				printf(" |   Ground                $%3d   |\n", property[players[i].position].rent[0]);
				printf(" |                                |\n");
				printf(" |   Color-Group           $%3d   |\n", property[players[i].position].rent[0] * 2);
				printf(" |                                |\n");
				printf(" |   With 1 House          $%3d   |\n", property[players[i].position].rent[1]);
				printf(" |                                |\n");
				printf(" |   With 2 Houses         $%3d   |\n", property[players[i].position].rent[2]);
				printf(" |                                |\n");
				printf(" |   With 3 Houses         $%3d   |\n", property[players[i].position].rent[3]);
				printf(" |                                |\n");
				printf(" |   With 4 Houses         $%3d   |\n", property[players[i].position].rent[4]);
				printf(" |                                |\n");
				printf(" |   With HOTEL            $%3d   |\n", property[players[i].position].rent[5]);
				printf(" | ------------------------------ |\n");
				printf(" |     Price of each House $%3d   |\n", property[players[i].position].price);
				printf(" |                                |\n");
				printf(" |     Mortgage amount 	   $%3d   |\n", property[players[i].position].mortgage);
				printf(" | ------------------------------ |\n");
				printf(" |                                |\n");
				printf(" __________________________________\n");
			}
			else if (strcmp(property[players[i].position].name, "CHANCE") == 0)
			{
				printf("\n             %s           \n", property[players[i].position].name);
				printf("Remove a CHANCE card...\n");
				int n = rand() % 15;
				printf("%s\n",cards[n].chance);
				fflush(stdin);
				getchar();
			}
			else if (strcmp(property[players[i].position].name, "COMMUNITY CHEST") == 0)
			{
				printf("\n             %s           \n", property[players[i].position].name);
				printf("Remove a letter from the COMMUNITY CHEST...\n");
				int n = rand() % 15;
				printf("%s\n",cards[n].com_chest);
				fflush(stdin);
				getchar();
			}
			else if (strcmp(property[players[i].position].name, "INCOME TAX") == 0)
			{
				printf("\n             %s           \n", property[players[i].position].name);
				printf("Pay M200 INCOME TAX.");
				fflush(stdin);
				getchar();
				players[i].balance -= 200;
				printf("\nCurrent Balance : %d", players[i].balance);
			}
			else if (strcmp(property[players[i].position].name, "SUPER TAX") == 0)
			{
				printf("\n             %s           \n", property[players[i].position].name);
				printf("Pay M100 SUPER TAX.");
				fflush(stdin);
				getchar();
				players[i].balance -= 100;
				printf("\nCurrent Balance : %d", players[i].balance);
			}
			else if ((strcmp(property[players[i].position].name, "JUST VISITING") == 0) && (strcmp(property[i].name, "FREE PARKING") == 0))
				printf("\n             %s           \n", property[players[i].position].name);
			else if (strcmp(property[players[i].position].name, "GO TO JAIL") == 0)
			{
				printf("\n             %s           \n", property[players[i].position].name);
				jail(i);
				fflush(stdin);
				getchar();
			}

			//Player Menu
			int option = 0;

			printf("\nWhat do you want to do?\n");
			printf("1 - Game State\n");
			if (strcmp(property[players[i].position].owner, "no owner") == 0)
			{
				printf("2 - Purchase Property\n");
				printf("3 - Auction Property\n");
			}
			if (strcmp(property[players[i].position].owner, players[i].name) == 0)
			{
				printf("4 - Build House\n");
				printf("5 - Build Hotel\n");
			}
			printf("6 - Sell property\n");
			printf("7 - Mortgage property\n");
			printf("0 - End turn\n");

		menuPlayer:
			printf("\nSelect your option: ");
			scanf("%d", &option);
			switch (option)
			{
			//1 - Game State
			case 1: 
				game_state(nplayers);
				goto menuPlayer;
				break;

			//2 - Purchase Property
			case 2: 
				if (strcmp(property[players[i].position].owner, "no owner") == 0)
					purchaseProperty(i);
				else 
					goto menuPlayer;
				break;

			//3 - Auction Property
			case 3: 
				auctionProperty(nplayers);
				break;

			//4 - Build House
			case 4: 
				buildHouses(i);
				break;

			//5 - Build Hotel
			case 5:
				printf("Not implemented!\n");
				break;

			//6 - Sell Property
			case 6: 
				printf("Not implemented!");
				break;

			//7 - Mortgage Property
			case 7: 
				mortgageProperty(i);
				break;

			//0 - End turn
			case 0:
				break;

			//option Invalid
			default: 
				printf("Error! Enter a valid option: \n");
				fflush(stdin);
				goto menuPlayer;
				break;
			}

			printf("\n\n\n");
			fflush(stdin);
			getchar();
			system("cls");
		}
		turn++;
	} while (turn != 999);

	system("pause");
}