#include "head.h"

//Two dice roll
int dice(int play)
{
	int dice1 = 0, dice2 = 0, total = 0, counter = 0, i = play;

	printf("\n========== Data Entry ==========\n");
	do
	{
		dice1 = (rand() % 6) + 1; 
		dice2 = (rand() % 6) + 1;

		printf(" * %d The roll: %d + %d = %d\n", counter + 1, dice1, dice2, dice1 + dice2);
		total += dice1 + dice2;
		if (dice1 != dice2)
		{
			printf("\nAdvance %d houses.\n", total);
			fflush(stdin);
			getchar();
			return total;
		}
		else
		{
			printf(" DOUBLE!\n\n");
			counter++;
			fflush(stdin);
			getchar();
		}
	} while ((dice1 == dice2) && (counter < 3));
	
	//3 doubles in a row --> Jail
	if (counter == 3)
	{
		printf("Obtained 3 consecutive DOUBLES. Go to jail!\n");
		fflush(stdin);
		getchar();
		jail(i);
		return (0);
	}
	else return total;
}