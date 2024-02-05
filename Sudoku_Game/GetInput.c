#include <stdio.h>
#include <stdlib.h>

//Abfrage des Vornahmens des Spielers
void GetSurname(char* namePlayer)
{
	char trash[80];
	while (0 == scanf_s("%50s", namePlayer, (unsigned)_countof(namePlayer)))
	{
		fgets(trash, 80, stdin);
		printf("Wie ist dein Vorname:");
	}
}

//Abfrage der Schwierigkeit
int GetDifficulty()
{
	int numbersInvisible = 0;
	printf("Wie viele Zahlen sollen ausgeblendet werden?");
	char trash[80];
	while (0 == scanf_s("%d", &numbersInvisible))
	{
		fgets(trash, 80, stdin);
		printf("Wie viele Zahlen sollen ausgeblendet werden? (Maximal 36)");
	}

	return numbersInvisible;
}
