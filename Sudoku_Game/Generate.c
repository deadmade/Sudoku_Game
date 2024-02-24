#include <stdio.h>
#include <stdlib.h>
#include "anyproject.h"
#include <time.h>

//Eine Zahl vom sudoku zufällig entfernen
void RemoveNumberSudoku(int sudoku[sudokuWidth][sudokuLength], int fieldsRemoved[sudokuWidth][sudokuLength])
{
	int randomNumberWidth = rand() % arrayLength;
	int randomNumberLength = rand() % arrayLength;

	if (sudoku[randomNumberWidth][randomNumberLength] != 0)
	{
		fieldsRemoved[randomNumberWidth][randomNumberLength] = 1;
		sudoku[randomNumberWidth][randomNumberLength] = -1;
	}
	else
	{
		RemoveNumberSudoku(sudoku, fieldsRemoved);
	}
}

//Eine bestimmt Anzahl an Zahlen vom Sudoku entfernen
void RemoveNumbersSudoku(int sudoku[sudokuWidth][sudokuLength], int amount,
                         int fieldsRemoved[sudokuWidth][sudokuLength])
{
	for (int i = 0; i < amount; i++)
	{
		RemoveNumberSudoku(sudoku, fieldsRemoved);
	}
}

//Ganze Zeile im Sudoku löschen(durch 0 ersetzen)
void deleteLine(int sudoku[sudokuWidth][sudokuLength], int line, int amountDeletedNumbers, int j)
{
	for (int i = 0; i <= amountDeletedNumbers; i++)
	{
		sudoku[line][(j-i)] = 0;
	}
}

void clearLine(int numbers[9])
{
	for (int i = 0; i < 9; i++)
	{
		numbers[i] = 0;
	}
}

//Generiert ein Sudoku zufällig
void GenerateSudoku(int sudoku[sudokuWidth][sudokuLength])
{
	srand(time(NULL));

	for (int i = 0; i < sudokuWidth; i++)
	{
		int amountDeletedNumbers = 1;
		for (int j = 0; j < sudokuLength; j++)
		{
			int numbers[9] = {0};
			int check = 0;
			int count = 0;
			while (check == 0)
			{
				if (count >= 9)
				{
					
					check = 1;
					if (amountDeletedNumbers > 9)
					{
						amountDeletedNumbers = 1;
					}
					deleteLine(sudoku, i, amountDeletedNumbers, j);
					j = j-amountDeletedNumbers;
					count = 0;
					clearLine(numbers);
					amountDeletedNumbers++;
				}

				int randomNumber = rand() % 9 + 1;

				if (numbers[randomNumber - 1] == 0) {
					numbers[randomNumber - 1] = 1;
					sudoku[i][j] = randomNumber;
					check = CheckSudoku(sudoku);			
					count++;
				}				
			}
		}
	}
}
