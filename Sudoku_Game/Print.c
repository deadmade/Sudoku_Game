#include <stdio.h>
#include "anyproject.h"

//Ändert die Konsolenschriftfarbe zu Blau
void printBlue()
{
	printf("%s", KCYN);
}

//Ändert die Konsolenschriftfarbe zu Weiß
void printWhite()
{
	printf("%s", KWHT);
}

//Ändert die Konsolenschriftfarbe zu Grün
void printGreen()
{
	printf("%s", KGRN);
}

//Ändert die Konsolenschriftfarbe zu Rot
void printRed()
{
	printf("%s", KRED);
}


//Gibt das Sudoku aus
void printSudoku(int sudoku[sudokuWidth][sudokuLength], char* namePlayer, int fieldsRemoved[sudokuWidth][sudokuLength])
{
	printf("Willkommen %s  \n", namePlayer);

	printBlue();
	printf("    A B C   D E F   G H I\n");
	printWhite();
	char* middle = "  +-------+-------+-------+\n";
	printf("%s", middle);
	for (int i = 1; i < sudokuWidth + 1; i++)
	{
		for (int j = 0; j < sudokuLength; j++)
		{
			if (j == 0)
			{
				printBlue();
				printf("%d", i);
				printWhite();
				printf(" | ");
			}
			//Feld, welches generiert wurde
			if (sudoku[i - 1][j] != 0 && fieldsRemoved[i - 1][j] == 0)
			{
				printGreen();
				printf("%d ", sudoku[i - 1][j]);
				printWhite();
			}
			//Feld welches vom Spieler bearbeitet wurde
			else if (sudoku[i - 1][j] != -1 && fieldsRemoved[i - 1][j] == 1)
			{
				printRed();
				printf("%d ", sudoku[i - 1][j]);
				printWhite();
			}
			//Noch leeres Feld
			else
			{
				printf("  ");
			}

			if ((j + 1) % 3 == 0)
				printf("| ");
		}
		printf("\n");
		if (i % 3 == 0 && i != 0)
		{
			printf("%s", middle);
		}
	}
}
