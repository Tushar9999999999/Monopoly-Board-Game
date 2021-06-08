#include "head.h"

//Menu 
int menu()
{
	int option;

	printf("MENU\n");
	printf("1 - New game\n");
	printf("2 - Credits\n");
	scanf("%d", &option);

	return(option);
}

//Game selection
int playerSelection()
{
	int nplayers;

	printf("Select number of players (2 to 8): ");
	scanf("%d", &nplayers);
	printf("\n");

	while ((nplayers < 2) || (nplayers > 8))
	{
		printf("Error! %d is not a valid number of players.\n", nplayers);
		printf("Select the number of players (2 to 8): ");
		scanf("%d", &nplayers);
	}
	getchar();
	for (int i = 0; i < nplayers; i++)
	{
		printf("Player %d name: ", i + 1);
		gets(players[i].name);
		players[i].balance = 1500;
		players[i].position = 0;
	}
	return (nplayers);
}

//Calculates the Player's new position after the Data Entry
int newposition(int posActual, int release)
{
	int newPos = posActual + release;

	if (newPos == 40)
	{
		newPos = 0;
		return (newPos);
	}
	else if (newPos > 40) 
		return(newPos - 40);
	else 
		return newPos;
}

//Purchase property
bool purchaseProperty(int play)
{
	int i = play;

	if (players[i].balance >= property[players[i].position].price)
	{
		players[i].balance -= property[players[i].position].price;
		strcpy(property[players[i].position].owner, players[i].name);

		printf("\nFull acquisition!\n");
		printf("%s was acquired by %s.\n", property[players[i].position].name, players[i].name);
		return (true);
	}
	else
	{
		printf("Player does not have enough balance for the acquisition!");
		printf("You need an additional M%d to complete the purchase.", property[players[i].position].price - players[i].balance);
		return (false);
	}
}

//Auction property
void auctionProperty(int numplay)
{
	int nplayers = numplay;
	int offer = 10, newoffer = 0;
	int counter = 0;
	bool auction = true;
	int option = 0;

	for (int i = 0; i < nplayers; i++)
	{
		players[i].auction = true;
	}

	do
	{
		for (int i = 0; i < nplayers; i++)
		{
			if (players[i].auction == true)
			{
				printf("\n== Player %d ==\n", i);
			menuauction:
				printf("What do you want to do?\n");
				printf(" 1 - Bid\n");
				printf(" 2 - Give up\n");
				printf("\nEnter an option: ");
				//fflush(stdin);
				scanf("%d", &option);

				switch (option)
				{
					//Bid
				bid:
					case 1:
						printf("Insert your offer: ");
						scanf("%d", &newoffer);
						if (newoffer <= offer)
						{
							printf("Please enter a value greater than %d.\n", offer);
							goto bid;
						}
						else if (newoffer > players[i].balance)
						{
							printf("Does not have enough balance for this offer.\n");
							players[i].auction = false; 
							printf("Player %d is out of auction \n", i);
							break;
						}
						else if ((newoffer - offer) >= 10)
						{
							printf("Player %d bids M%d \n", i, newoffer);
							offer = newoffer;
							break;
						}
						else
						{
							printf("Need to bid higher than M10 \n");
							goto bid;
						}
						break;

					//Give up
					case 2:
						printf("Withdraw from auction. \n");
						printf("Player %d is out of auction \n", i);
						players[i].auction = false;
						counter++;
						break;

					//option Invalid
					default:
						printf("Invalid insertion");
						goto menuauction;
						break;
				}
			}
		}
		if (counter == nplayers - 1) 
			auction = false;
	} while (auction == true);
}

//Build Houses
void buildHouses(int play)
{
	int i = play;
	int colorcounter = 0;
	int dicecounter = 0;
	int colorcodes[3];

	for (int j = 0; j < 40; j++)
	{
		//Keep the property codes with the same color
		for (int k = 0; k < 3; k++)
		{
			if (strcmp(property[players[i].position].color, property[j].color) == 0)
			{
				colorcounter++;
				colorcodes[k] = j;
			}
		}

		//Check if these properties belong to the Player who intends to build Houses
		for (int k = 0; k < colorcounter; k++)
		{
			if (strcmp(property[colorcodes[k]].owner, players[i].name) == 0)
			{
				dicecounter++;
				if (colorcounter == dicecounter)
				{
					property[players[i].position].nhouses++;
					printf("Successfully built house!\n");
					printf("This Property now has %d House(s).\n", property[players[i].position].nhouses);
				}
				else printf("Player does not have the %d properties needed to build houses.", colorcounter);
			}
		}
	}
}

//Mortgage properties
void mortgageProperty(int play)
{
	int i = play;
	int option = 0;
	printf("Want to mortgage - %s - by M%d ?\n", property[i].name, (property[i].price / 2));
	printf(" 1 - Yes\n");
	printf(" 0 - No\n");

menumortgage:
	printf("Enter an option: ");
	scanf("%d", &option);
	switch (option)
	{
		case 1:
			property[players[i].position].mortgage = true;
			printf("A Property %s was mortgaged.\n", property[i].name);
			fflush(stdin);
			getchar();
			break;
		case 2:
			break;
		default:
			printf("Error! option invalid.\n");
			fflush(stdin);
			getchar();
			goto menumortgage;
			break;
	}
}