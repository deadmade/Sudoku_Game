#include <stdio.h>
#include "anyproject.h"

//Initial Methode um zu Überprüfen ob der Spieler gewonnen hat
int CheckWinner(int sudoku[sudokuWidth][sudokuLength])
{
	int check = CheckSudoku(sudoku);
	if (check == 1)
	{
		printf("Hervorragend. Sie haben das Kuchentastische Sudoku geloest.");
		return 1;
	}
	printf("Dumm Dumm Dumm. Sie haben was falsch gemacht\n");
	return 0;
}

//Macht Speziall Zeig wenn Koordinatne 0 0 eingegeben wird
int CheckNumber(int sudokuPlayer[sudokuWidth][sudokuLength], int number, int sudokuSolved[sudokuLength][sudokuWidth],
                int* counter,
                struct PlayerMove playerMoves[arrayLength], int fieldsRemoved[sudokuWidth][sudokuLength])
{
	if (number == 0)
	{
		return CheckWinner(sudokuPlayer);
	}
	else if (number == 1)
	{
		//Benötigt um die Lösung zu zeigen. Sonst sehr komsich
		int nothing[sudokuWidth][sudokuLength] = {0};
		printSudoku(sudokuSolved, "du Cheater", nothing);
		return 2;
	}
	else if (number == 2)
	{
		return 0;
	}
	else if (number == 3)
	{
		printf("Bye Bye du Pisser");
		return 1;
	}
	else if (number == 4)
	{
		*counter = ConvertCounter(*counter, 0);
		if (fieldsRemoved[playerMoves[*counter].horizontalCoordinate][playerMoves[*counter].verticalCoordinate] == 1)
		{
			sudokuPlayer[playerMoves[*counter].horizontalCoordinate][playerMoves[*counter].verticalCoordinate] =
				playerMoves[*counter].numberBefore;
		}

		return 0;
	}
	else
	{
		printf("Falsche Eingabe\n");
	}
	
	return 0;
}

//Überprüfen ob eine Zahl zwischen 1 und 9 ist
int CheckInputNumberIsValid(int number)
{
	switch (number)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return 1;
	default:
		return 0;
	}
}

//Überprüft was der Spieler eingegeben hat und welche Aktion gemacht werden soll
int CheckUserInput(int sudokuPlayer[sudokuWidth][sudokuLength], int horizontalCoordinate, int verticalCoordinate,
                   int fieldsRemoved[sudokuWidth][sudokuLength], int number,
                   int sudokuSolved[sudokuLength][sudokuWidth], int* counter,
                   struct PlayerMove playerMoves[arrayLength])
{
	//Eingabe 00 0 -> Ergebnis Prüfen
	//Eingabe 00 1 -> Lösung anzeigen
	//Eingabe 00 2 -> Lösung nicht mehr anzeigen
	//Eingabe 00 3 -> Spiel beenden
	//Eingabe 00 4 -> Letzten Zug rückgängig machen

	if (horizontalCoordinate == 0 && verticalCoordinate == 0)
	{
		return CheckNumber(sudokuPlayer, number, sudokuSolved, counter, playerMoves, fieldsRemoved);
	}
	if (fieldsRemoved[horizontalCoordinate - 1][verticalCoordinate] == 1 && CheckInputNumberIsValid(number) == 1)
	{
		struct PlayerMove move = {
			horizontalCoordinate - 1, verticalCoordinate, sudokuPlayer[(horizontalCoordinate - 1)][verticalCoordinate],
			number
		};
		playerMoves[*counter] = move;

		int test = playerMoves[*counter].numberBefore;

		sudokuPlayer[(horizontalCoordinate - 1)][verticalCoordinate] = number;

		*counter = ConvertCounter(*counter, 1);

		return 0;
	}
	printf("Falsche Eingabe\n");
	return 0;
}

int UserInputActions(int sudokuPlayer[sudokuWidth][sudokuLength],
                     int fieldsRemoved[sudokuWidth][sudokuLength], int sudokuSolved[sudokuLength][sudokuWidth],
                     char coordinatsUserInput[3],
                     int number, int cancel, int* counter, struct PlayerMove playerMoves[9])
{
	int firstCoordinate = ConvertLetterToNumber(coordinatsUserInput[0]);
	int secondCoordinate = ConvertLetterToNumber(coordinatsUserInput[1]);
	if (cancel == 2 && coordinatsUserInput[0] != '0' && coordinatsUserInput[1] != '0')
	{
		printf("Blende die Loesung zuerst aus, dann kannst du weiter machen!\n");
	}
	else if (coordinatsUserInput[0] == '0' && coordinatsUserInput[1] == '0')
	{
		return CheckUserInput(sudokuPlayer, 0, 0, fieldsRemoved, number, sudokuSolved, counter, playerMoves);
	}
	else if (firstCoordinate == -1 && secondCoordinate != -1)
	{
		int verticalCoordinate = ConvertCharToInt(coordinatsUserInput[0]);
		if (verticalCoordinate != -1)
		{
			return CheckUserInput(sudokuPlayer, verticalCoordinate, secondCoordinate, fieldsRemoved, number,
			                      sudokuSolved, counter, playerMoves);
		}
		printf("Falsche Eingabe\n");
	}
	else if (firstCoordinate != 1 && secondCoordinate == -1)
	{
		int verticalCoordinate = ConvertCharToInt(coordinatsUserInput[1]);
		if (verticalCoordinate != -1)
		{
			return CheckUserInput(sudokuPlayer, verticalCoordinate, firstCoordinate, fieldsRemoved, number,
			                      sudokuSolved, counter, playerMoves);
		}
		printf("Falsche Eingabe\n");
	}
	else
	{
		printf("Falsche Eingabe\n");
	}
	return 0;
}
