#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "anyproject.h"

#define extern "C";

//Kopiert einen 2D Array in einen anderen 2D Array
void copy2DArray(int dest[sudokuWidth][sudokuLength], int src[sudokuWidth][sudokuLength])
{
	for (int i = 0; i < sudokuWidth; i++)
	{
		for (int j = 0; j < sudokuLength; j++)
		{
			dest[i][j] = src[i][j];
		}
	}
}

//Bereitet das Spiel vor. Generiert das Sudoku, gibt die Regeln aus, fragt nach dem Namen des Spielers und nach der Schwierigkeit
void PrepeareGame(int sudoku[sudokuWidth][sudokuLength], char* namePlayer, int fieldsRemoved[sudokuWidth][sudokuLength],
                  int sudokuSolved[sudokuWidth][sudokuLength])
{
#ifdef _DEBUG
	clock_t start, end;
	double timeTaken;
	start = clock();
#endif


	GenerateSudoku(sudoku);
#ifdef _DEBUG
	end = clock();
	timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

	printf("Time taken to generate the sudoku: %f\n", timeTaken);
#endif



	copy2DArray(sudokuSolved, sudoku);
	PrintRules();
	GetSurname(namePlayer);
	int numbersInvisible = GetDifficulty();
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
	//Sudoku welches der Spieler nicht sehen kann und welches die L�sung ist
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
		if (cancel != 2)
		{
			printSudoku(sudokuPlayer, namePlayer, fieldsRemoved);
		}

		char coordinatsUserInput[3];
		int number = 0;

		printf("Bitte geben sie etwas ein:");
		char trash[80];
		while (0 == scanf_s("%2s %1d", coordinatsUserInput, (unsigned)_countof(coordinatsUserInput), &number))
		{
			fgets(trash, 80, stdin);
			printf("Bitte geben sie etwas ein:");
		}

		//Konsole clearen. Geht nur unter Windows
		system("cls");

		cancel = UserInputActions(sudokuPlayer, fieldsRemoved, sudokuSolved, coordinatsUserInput, number, cancel,
		                          &counter, playerMoves);
	}

	return 0;
}
