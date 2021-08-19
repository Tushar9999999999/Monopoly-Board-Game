#include "game.h"

int main()
{
    if (Intro()!=EXIT_SUCCESS){
        printf("\nIntro Error\n");
        return EXIT_FAILURE;
    }
    char choice;
    while(TRUE)
    {
        clearScreen();
        printf("MONOPOLY\n\n\n");
        printf("\n\t  1-Play Monopoly");
        printf("\n\t  2-Read Rules");
        printf("\n\t  X-Exit\n\n");
        choice = getch();
        if (choice == '1')
        {
            if (mainGame()!=EXIT_SUCCESS)
            {
                printf("\nError in main Game\n");
                return EXIT_FAILURE;
            }
        }
        else if (choice == '2'){
            if (ShowRules()!=EXIT_SUCCESS)
            {
                printf("\nError in showing rules\n");
                return EXIT_FAILURE;
            }    
        }
        else if (choice == 'X'|| choice == 'x')
        {
            clearScreen();
            if (ThankYou()!=EXIT_SUCCESS)
            {
                printf("\nError in Thank You screen\n");
                return EXIT_FAILURE;
            }  
            clearScreen();
            return EXIT_SUCCESS;
        }
        else
        {
            printf("\n\n\tYou entered an invalid choice \"%c\". Enter any key to try again.",choice);
            getch();
        }
    }
    return EXIT_SUCCESS;
}
