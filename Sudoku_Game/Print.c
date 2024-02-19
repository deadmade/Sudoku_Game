#include <stdio.h>
#include "anyproject.h"

//�ndert die Konsolenschriftfarbe zu Blau
void printBlue()
{
	printf("%s", KCYN);
}

//�ndert die Konsolenschriftfarbe zu Wei�
void printWhite()
{
	printf("%s", KWHT);
}

//�ndert die Konsolenschriftfarbe zu Gr�n
void printGreen()
{
	printf("%s", KGRN);
}

//�ndert die Konsolenschriftfarbe zu Rot
void printRed()
{
	printf("%s", KRED);
}

//Gibt die Regeln f�r die Eingabe des Spielers aus
void PrintUserInputActionRules()
{
	printf("\nEingabe 00 0 -> Ergebnis Pruefen\n");
	printf("Eingabe 00 1 -> Loesung anzeigen\n");
	printf("Eingabe 00 2 -> Loesung nicht mehr anzeigen\n");
	printf("Eingabe 00 3 -> Spiel beenden\n");
	printf("Eingabe 00 4 -> Letzten Zug rueckgaengig machen\n\n");
}


//Ausgabe der Regeln eines Sudokus
void PrintRules()
{
	printf("Willkommen zum Kuchtastsichen Sudoku \n");
	printf("Die Spielregeln sind wie folgt: \n");
	printf("In jeder Zeile, Spalte und 3x3 darf nur einmal die Zahlen 1-9 vorkommen\n");
	printf("Wie lautet dein Vorname:");
}

//Gibt das Sudoku aus
void printSudoku(int sudoku[sudokuWidth][sudokuLength], char* namePlayer, int fieldsRemoved[sudokuWidth][sudokuLength])
{
	printf("Willkommen %s  \n", namePlayer);

	PrintUserInputActionRules();

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
				printf("* ");
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



	
