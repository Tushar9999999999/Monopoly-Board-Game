// System specific
#define SCREENSIZE_X    172
#define SCREENSIZE_Y    40

// Can be changed according to game requirement
#define INITIAL_AMT     1500                // Amount of money each player start with
#define BANKRUPT_VALUE  0                   // Min value of cash in hand to be not bankrupt
#define MAX_DOUBLES     3                   // Maximum die doubles a player can roll

// Path location of csv file
#define LOCATION_PATH   "property.csv"

#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define clearScreen()   system("cls")
#define goto_XY(X,Y)    printf("\e[%d;%df",Y,X)
#define hideCursor()    printf("\e[?25l")
#define showCursor()    printf("\e[?25h")
#define colour(C1,C2)   printf("\033[%d;%dm",C2,C1)

enum Boolean  {FALSE,TRUE};
enum colours  {RESET,INCREASED_INTENSITY,BLACK=30,RED,GREEN,YELLOW,BLUE,PURPLE,CYAN,WHITE,\
               RED_BG=41,GREEN_BG,YELLOW_BG,BLUE_BG,PURPLE_BG,CYAN_BG,WHITE_BG,\
               LIGHTBLACK_BG=100,LIGHTRED_BG,LIGHTGREEN_BG,LIGHTYELLOW_BG,LIGHTBLUE_BG,LIGHTPURPLE_BG,LIGHTCYAN_BG,PUREWHITE_BG}; 
enum GameMode {NETWORTH,TURNS,ENDLESS,EXIT};
enum csvHead  {ID_H,LocType_H,LocName_H,SetID_H,SetColour_H,Cost_H,Rent_H,H1_H,H2_H,H3_H,H4_H,Hotel_H,BuildCost_H};
enum LocType  {FREE,CHEST,CHANCE,JAIL,TAX,UTILITY,RAIL,PROPERTY};
enum CardType {BAD=-1,NEUTRAL,GOOD};
enum MainMenu {ROLL,BUY,SELL,GIVEUP};

// Structure containing location information
struct location
{       
    unsigned int ID  :6;                    // Uniquely identify location (1-40)
    unsigned int type:3;                    // Type of location: FREE/CHEST/CHANCE/JAIL/TAX/UTILITY/RAIL/PROPERTY
    unsigned int isOwnable:1;               // If the location be owned currently by a player
    char name[30];                          // Name of the location
    unsigned short int cost:10;             // Cost to buy the location 
    unsigned int setID:4;                   // Identify properties by set ID
    int setColour:8;                        // Colour associated with set
    unsigned short int initialRent:10;      // Initial rent of the property
    unsigned short int house[4];            // Rents with 1-4 houses 
    unsigned short int  hotel:10;           // Rents with 1 hotel
    unsigned short int buildCost:10;        // Cost of building a house or hotel
    unsigned int ownerID:4;                 // If owned, current owner's ID else 0
    unsigned int isSetComplete:1;           // If the set is complete
    unsigned int housesBuilt:3;             // Amount of houses built on the property
    unsigned int hotelBuilt:1;              // If a hotel is built on the property 
    int rent;                               // Current rent of the property
}\
Location[40];                               // Locations read from csv file

// Structure containing card information
struct card
{
    int type:3;                             // Type of card: BAD/NEUTRAL/GOOD
    unsigned int money;                     // Money associated with the card
    unsigned int locationID:6;              // Location ID associated with card 
}drawnCard;

// Structure containing player information
struct player
{
    unsigned int ID:4;                      // Uniquely identify player
    char name[30];                          // Name of player
    unsigned int colour1:7,colour2:7;       // Colour of player on screen
    short int netWorth;                     // The net worth of the player
    short int cashInHand;                   // Amount of cash player currently has  
    unsigned int isOut:1;                   // If the player is out of the game
    unsigned int isBankrupt:1;              // If the player is bankrupt
    unsigned int isInJail:1;                // If the player is in jail
    unsigned int jailTurn:2;                // Number of turns player left to leave jail
    struct location *currentLocation;       // The current location of the player (structure)
    unsigned short int propertyOwnedCount:6;// Amount of properties the player owns
    unsigned short int propertyOwned[20];   // Lists of properties the player owns
    unsigned int position:4;                // Position of the player post-game
};


// Accepts game mode choice from user 
// Returns the choice NETWORTH/TURNS/ENDLESS/EXIT
int SelectGamemode();

// Reads location informations from file and stores them in structures
// Returns EXIT_SUCCESS if read properly
int ReadLocations();

// Generates random card information from locations file based on card type and stores it in a structure
// Returns EXIT_SUCCESS if read properly
int GenerateCard();

// Clears screen and displays monopoly map
// Returns EXIT_SUCCESS if displayed properly
int DisplayMap();

// Displays Property information graphically
// Returns EXIT_SUCCESS if displayed properly
int GraphicalPropertyInfo(struct player Players[],int playerCount);

// Emulates player rolling a die
// Returns a random integer from 1-6
int PlayerRolls();

// Reads number of players and player names
// Returns EXIT_SUCCESS if read properly
int ReadPlayers(int *numberOfPlayers, char (*Names)[30]);

// Each player rolls two dice and player order is set according to highest values
// Returns EXIT_SUCCESS if set properly
int SetPlayerOrder(int numberOfPlayers, char (*Names)[30]);

// Initialise Player structure values
// Returns EXIT_SUCCESS if set properly
int InitialisePlayers(struct player Player[],int PlayerCount, char (*Names)[30]);

// Places the player on the screen according to their current position and clears the previous one
// Returns EXIT_SUCCESS if set properly
int GraphicalMove(struct player *currentPlayer,int OldLocationID,int NewLocationID);

// Accepts an integer input from the user within certain time
// Returns the integer or else returns the Default value given when time elapses
int TimedNumInput(int seconds,int Default);

// Accepts a character input from the user within certain time
// Returns the character or else returns the Default value given when time elapses
char TimedCharInput(int seconds,char Default);

// Clears right part of the screen form line given
// Returns EXIT_SUCCESS if cleared properly
int ClearRightScreen(int startLine);

// Player Menu with timed input
// Returns player choice: ROLL/BUY/SELL/GIVEUP
int PlayerMainMenu(struct player *CurrentPlayer);

// Calculates rent of location the player is currently on based on location type
// Returns rent of the location
int RentCalc(struct player *owner ,struct location *currentLocation, int rolled);

// Sell Menu for current player based on locations they own
// Returns EXIT_SUCCESS on success
int SellMenu(struct player *CurrentPlayer);

// Buy houses and hotels Menu for current player based on locations they own
// Returns EXIT_SUCCESS on success
int BuyHousesMenu(struct player *CurrentPlayer);

// Buy Property Menu for location player lands on
// Returns EXIT_SUCCESS on success
int BuyMenu(struct player *CurrentPlayer,struct location *currentLocation);

// Checks if player is bankrupt 
// Returns TRUE/FALSE
int IsPlayerBankrupt(int cashInHand);

// Shows leaderboards post game
// Returns EXIT_SUCCESS on successful display
int PlayerResults(struct player Player[],int PlayerCount);

// Clears screen and displays intro screen "WELCOME TO MONOPOLY"
// Returns EXIT_SUCCESS when displayed properly
int Intro();

// Clears screen and displays rules of monopoly
// Returns EXIT_SUCCESS when displayed properly
int ShowRules();

// Clears screen and displays rules of monopoly
// Returns EXIT_SUCCESS after game played successfully
int mainGame();

// Clears screen and displays intro screen "THANKS FOR PLAYING"
// Returns EXIT_SUCCESS when displayed properly
int ThankYou();