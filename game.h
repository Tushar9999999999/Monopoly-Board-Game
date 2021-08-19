#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define SCREENSIZE_X    172
#define SCREENSIZE_Y    40
#define INITIAL_AMT     1500              
#define BANKRUPT_VALUE  0                  
#define MAX_DOUBLES     3                 
#define LOCATION_PATH   "property.csv"
#define clearScreen()   system("cls")
#define goto_XY(X,Y)    printf("\e[%d;%df",Y,X)
#define colour(C1,C2)   printf("\033[%d;%dm",C2,C1)

enum Boolean  {FALSE,TRUE};
enum colours  {INCREASED_INTENSITY=1,BLACK=30,RED,GREEN,YELLOW,BLUE,PURPLE,CYAN,WHITE,\
               RED_BG=41,GREEN_BG,YELLOW_BG,BLUE_BG,PURPLE_BG,CYAN_BG,WHITE_BG,\
               LIGHTBLACK_BG=100,LIGHTRED_BG,LIGHTGREEN_BG,LIGHTYELLOW_BG,LIGHTBLUE_BG,LIGHTPURPLE_BG,LIGHTCYAN_BG,PUREWHITE_BG}; 
enum GameMode {NETWORTH,TURNS,ENDLESS,EXIT};
enum csvHead  {ID_H,LocType_H,LocName_H,SetID_H,SetColour_H,Cost_H,Rent_H,H1_H,H2_H,H3_H,H4_H,Hotel_H,BuildCost_H};
enum LocType  {FREE,CHEST,CHANCE,JAIL,TAX,UTILITY,RAIL,PROPERTY};
enum CardType {BAD=-1,NEUTRAL,GOOD};
enum MainMenu {ROLL,BUY,SELL,GIVEUP};

struct location
{       
    int ID;        
    int type;     
    int isOwnable;           
    char name[30];                     
    int cost;       
    int setID;               
    int setColour;                     
    int initialRent;   
    int house[4];       
    int hotel;
    int buildCost;       
    int ownerID;        
    int isSetComplete;     
    int housesBuilt;           
    int hotelBuilt;  
    int rent;                   
}Location[40];                    

struct card
{
    int type;           
    unsigned int money;                
    unsigned int locationID:6;     
}drawnCard;

struct player
{
    int ID;            
    char name[30];               
    int colour1,colour2; 
    int netWorth;            
    int cash;
    int isOut;           
    int isBankrupt;  
    int isInJail;       
    int jailTurn;          
    struct location *currentLocation;    
    int propertyOwnedCount;
    int propertyOwned[20];   
    int position;              
};

int SelectGamemode();
int ReadLocations();
int GenerateCard();
int DisplayMap();
int GraphicalPropertyInfo(struct player Players[],int playerCount);
int PlayerRolls();
int ReadPlayers(int *numberOfPlayers, char (*Names)[30]);
int SetPlayerOrder(int numberOfPlayers, char (*Names)[30]);
int InitialisePlayers(struct player Player[],int PlayerCount, char (*Names)[30]);
int GraphicalMove(struct player *currentPlayer,int OldLocationID,int NewLocationID);
int ClearRightScreen(int startLine);
int PlayerMainMenu(struct player *CurrentPlayer);
int RentCalc(struct player *owner ,struct location *currentLocation, int rolled);
int SellMenu(struct player *CurrentPlayer);
int BuyHousesMenu(struct player *CurrentPlayer);
int BuyMenu(struct player *CurrentPlayer,struct location *currentLocation);
int IsPlayerBankrupt(int cash);
int PlayerResults(struct player Player[],int PlayerCount);
int Intro();
int ShowRules();
int mainGame();
int ThankYou();
