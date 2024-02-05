#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "anyproject.h"

#define extern "C";

struct PlayerMove
{
	int horisontal;
	int vertical;
	int number;
};

//Konvertierung von Buchstaben zu Zahlen
int ConvertLetterToNumber(char letter)
{
	switch (toupper(letter))
	{
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	case 'H':
		return 7;
	case 'I':
		return 8;
	default:
		return -1;
	}
}

//Ausgabe der Regeln eines Sudokus
void PrintRules()
{
	printf("Willkommen zum Kuchtastsichen Sudoku \n");
	printf("Die Spielregeln sind wie folgt: \n");
	printf("In jeder Zeile, Spalte und 3x3 darf nur einmal die Zahlen 1-9 vorkommen\n");
	printf("Wie ist dein Vorname:");
}

//Initial Methode um zu Überprüfen ob der Spieler gewonnen hat
int CheckWinner(int sudoku[sudokuWidth][sudokuLength])
{
	int check = CheckSudoku(sudoku);
	if (check == 1)
	{
		printf("Hervorragend. Sie haben das Kuchentastische Sudoku geloest.");
		return 1;
	}
	printf("Dumm Dumm Dumm. Sie haben was falsch gemacht");
	return 0;
}

//Bereitet das Spiel vor. Generiert das Sudoku, gibt die Regeln aus, fragt nach dem Namen des Spielers und nach der Schwierigkeit
void PrepeareGame(int sudoku[sudokuWidth][sudokuLength], char* namePlayer, int fieldsRemoved[sudokuWidth][sudokuLength],
                  int sudokuSolved[sudokuWidth][sudokuLength])
{
	int numbersInvisible = 0;
	GenerateSudoku(sudoku);
	sudokuSolved = sudoku;
	PrintRules();
	GetSurname(namePlayer);
	numbersInvisible = GetDifficulty();
	while (numbersInvisible >= 36 || numbersInvisible <= 17)
	{
		numbersInvisible = GetDifficulty();
	}
	RemoveNumbersSudoku(sudoku, numbersInvisible, fieldsRemoved);
}

int main()
{
	//Sudoku welches der Spieler sehen kann und bearbeiten kann
	int sudokuPlayer[sudokuLength][sudokuWidth] = {0};
	//Sudoku welches der Spieler nicht sehen kann und welches die Lösung ist
	int sudokuSolved[sudokuLength][sudokuWidth] = {0};
	//Felder die der Spieler bearbeiten kann
	int fieldsRemoved[sudokuWidth][sudokuLength] = {0};
	struct PlayerMove playerMoves[9] = {0};
	//Name des Spielers
	char namePlayer[50];
	//Entscheidet, wann das Spiel beendet wird
	int cancel = 0;

	PrepeareGame(sudokuPlayer, namePlayer, fieldsRemoved, sudokuSolved);


	while (cancel == 0)
	{
		printSudoku(sudokuPlayer, namePlayer, fieldsRemoved);
		int horisontal = 0;
		char vertical = ' ';
		int number = 0;

		printf("Bitte geben sie etwas ein:");
		char trash[80];
		while (0 == scanf_s("%1d %1c %1d", &horisontal, &vertical, sizeof(vertical), &number) == 3)
		{
			fgets(trash, 80, stdin);
			printf("Bitte geben sie etwas ein:");
		}

		int verticalNumber = ConvertLetterToNumber(vertical);

		//Bedingung ob das Spiel gechekt wird, ob der Spieler gewonnen hat
		if (horisontal == 0 && verticalNumber == -1)
		{
			cancel = CheckWinner(sudokuPlayer);
		}
		//TODO Check UserInput :(
		//Überprüfung ob der User das Feld bearbeiten kann
		else if (fieldsRemoved[horisontal-1][verticalNumber] == 1)
		{
			sudokuPlayer[(horisontal - 1)][verticalNumber] = number;
		}
		//Konsole clearen. Geht nur unter Windows
		system("cls");
	}
	return 0;
}
