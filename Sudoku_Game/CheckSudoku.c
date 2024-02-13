#include "anyproject.h"
#define extern "C";

//Überprüft einen Array ob doppelte Zahlen vorhanden sind(nur von 1-9)
int checkArray(const int toCheck[9])
{
	int rightArray[arrayLength] = numberArrayWithoutZero;
	for (int i = 0; i < arrayLength; ++i)
	{
		int counter = 0;
		for (int j = 0; j < 9; ++j)
		{
			if (toCheck[j] == -1)
			{
				return 0;
			}
			if (toCheck[j] == rightArray[i])
			{
				counter = counter + 1;
			}
			if (counter > 1)
			{
				return 0;
			}
		}
	}
	return 1;
}

//Überprüft eine Zeile des Sudokus ob dieses Doppelte Zahlen enthält
int CheckLine(int sudoku[sudokuWidth][sudokuLength], int line)
{
	int arrayToCheck[arrayLength] = zeroArray;
	for (int i = 0; i < arrayLength; ++i)
	{
		arrayToCheck[i] = sudoku[line][i];
	}
	int check = checkArray(arrayToCheck);
	return check;
}

//Überprüft eine Spalte des Sudokus ob dieses Doppelte Zahlen enthält
int CheckRow(int sudoku[sudokuWidth][sudokuLength], int row)
{
	int arrayToCheck[arrayLength] = zeroArray;
	for (int i = 0; i < arrayLength; ++i)
	{
		arrayToCheck[i] = sudoku[i][row];
	}
	int check = checkArray(arrayToCheck);
	return check;
}

//Überprüft ein 3x3 Feld des Sudokus ob dieses Doppelte Zahlen enthält
int CheckBox(int sudoku[sudokuWidth][sudokuLength], int boxX, int boxY)
{
	int arrayToCheck[arrayLength] = zeroArray;
	int counter = 0;
	for (int i = 0; i < (sudokuLength / 3); ++i)
	{
		for (int j = 0; j < (sudokuWidth / 3); ++j)
		{
			arrayToCheck[counter] = sudoku[boxX + i][boxY + j];
			counter = counter + 1;
		}
	}
	int check = checkArray(arrayToCheck);
	return check;
}

//Überprüft das gesamte Sudoku ob dieses Doppelte Zahlen enthält
int CheckSudoku(int sudoku[sudokuWidth][sudokuLength])
{
	for (int i = 0; i < sudokuWidth; ++i)
	{
		if (CheckLine(sudoku, i) == 0)
		{
			return 0;
		}
	}
	for (int i = 0; i < sudokuLength; ++i)
	{
		if (CheckRow(sudoku, i) == 0)
		{
			return 0;
		}
	}
	for (int i = 0; i < 7;)
	{
		for (int j = 0; j < 7;)
		{
			if (CheckBox(sudoku, i, j) == 0)
			{
				return 0;
			}
			j = j + 3;
		}
		i = i + 3;
	}

	return 1;
}
