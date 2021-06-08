#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void initialize_board();
int menu();
int playerSelection();
void jail(int);
int dice(int);
int newposition(int, int);
void game_state(int);
bool purchaseProperty(int);
void auctionProperty(int);
void buildHouses(int);
void mortgageProperty(int);
void cardsSelector();

//User defined data structure for property
typedef struct property
{
	char name[50];
	char color[10];
	int price;
	int rent[6];
	int nhouses;	
	int mortgageprice;
	int housecost;
	bool mortgage;
	char owner[20];
} Property;

Property property[40];

//User defined data structure for registering players
typedef struct players
{
	char name[50];
	int balance;
	int position;
	bool auction;
	int jail;
} Player;

Player players[8];

typedef struct cards
{
	char chance[50];
	char com_chest[50];
} Cards;

Cards cards[20];