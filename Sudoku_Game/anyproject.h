#pragma once
//extern "C" int ConvertLetterToNumber(char letter);

#define sudokuLength 9
#define sudokuWidth 9
#define arrayLength 9
#define zeroArray {0, 0, 0, 0, 0, 0, 0, 0, 0}
#define numberArrayWithoutZero {1, 2, 3, 4, 5, 6, 7, 8, 9}
#define numberArrayWithZero {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
#define sudokuFields 81

#define KNRM  "\x1B[0m"    // normal
#define KRED  "\x1B[31m"   // red
#define KGRN  "\x1B[32m"   // green
#define KYEL  "\x1B[33m"   // yellow
#define KBLU  "\x1B[34m"   // blue
#define KMAG  "\x1B[35m"   // magenta
#define KCYN  "\x1B[36m"   // cyab
#define KWHT  "\x1B[37m"   // white


int CheckSudoku(int sudoku[sudokuWidth][sudokuLength]);
void GenerateSudoku(int sudoku[sudokuWidth][sudokuLength]);
void GetSurname(char* namePlayer);
int GetDifficulty();
void RemoveNumbersSudoku(int sudoku[sudokuWidth][sudokuLength], int amount,
                         int fieldsRemoved[sudokuWidth][sudokuLength]);
void printSudoku(int sudoku[sudokuWidth][sudokuWidth], char* namePlayer,
                 int fieldsRemoved[sudokuWidth][sudokuLength]);
int ConvertLetterToNumber(char letter);
int ConvertCounter(int counter, int direction);
int ConvertCharToInt(int character);
int UserInputActions(int sudokuPlayer[sudokuWidth][sudokuLength],
                     int fieldsRemoved[sudokuWidth][sudokuLength], int sudokuSolved[sudokuLength][sudokuWidth],
                     char coordinatsUserInput[3],
                     int number, int cancel, int* counter, struct PlayerMove playerMoves[9]);

struct PlayerMove
{
	int horizontalCoordinate;
	int verticalCoordinate;
	int numberBefore;
	int numberAfter;
};
