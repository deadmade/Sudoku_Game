#include <stdio.h>
#include <stdlib.h>
#include "anyproject.h"

#define extern "C";

struct PlayerMove
{
	int horisontal;
	int vertical;
	int number;
};

//Ausgabe der Regeln eines Sudokus
void PrintRules()
{
	printf("Willkommen zum Kuchtastsichen Sudoku \n");
	printf("Die Spielregeln sind wie folgt: \n");
	printf("In jeder Zeile, Spalte und 3x3 darf nur einmal die Zahlen 1-9 vorkommen\n");
	printf("Wie lautet dein Vorname:");
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
	while (numbersInvisible > 36 || numbersInvisible < 17)
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
	int counter = 0;

	PrepeareGame(sudokuPlayer, namePlayer, fieldsRemoved, sudokuSolved);


	while (cancel != 1)
	{
		printSudoku(sudokuPlayer, namePlayer, fieldsRemoved);
		int horisontal = 0;
		char coordinatsUserInput[3];
		int number = 0;

		printf("Bitte geben sie etwas ein:");
		char trash[80];
		while (0 == scanf_s("%2s %1d",coordinatsUserInput, (unsigned)_countof(coordinatsUserInput), &number))
		{
			fgets(trash, 80, stdin);
			printf("Bitte geben sie etwas ein:");
		}

		UserInputActions(sudokuPlayer, fieldsRemoved, sudokuSolved, coordinatsUserInput, number, cancel);

		//Konsole clearen. Geht nur unter Windows
		//system("cls");

		
	}
	return 0;
}
