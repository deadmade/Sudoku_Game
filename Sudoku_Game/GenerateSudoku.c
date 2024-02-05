//#include "CheckSudoku.c"
#include "anyproject.h"



int *CheckArrayGenerator(const int toCheck[arrayLength], int *availableNumbers) {
    int rightArray[arrayLength] = numberArray;
    int counterNumbers[arrayLength] = zeroArray;

    for (int i = 0; i < sudokuLength; ++i) {
        int counter = 0;
        for (int j = 0; j < sudokuWidth; ++j) {
            if (toCheck[j] == rightArray[i]) {
                counter = counter + 1;
                counterNumbers[i] = counter;
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < arrayLength; ++i) {
        if (counterNumbers[i] == 0) {
            availableNumbers[counter] = rightArray[i];
            counter = counter + 1;
        }
    }
    return availableNumbers;
}

void CheckLineGenerator(int sudoku[sudokuWidth][sudokuLength], int line, int* availableNumbers) {
    int arrayToCheck[arrayLength] = zeroArray;
    for (int i = 0; i < sudokuLength; ++i) {
        arrayToCheck[i] = sudoku[line][i];
    }
    CheckArrayGenerator(arrayToCheck, availableNumbers);
}

void CheckRowGenerator(int sudoku[sudokuWidth][sudokuLength], int row, int *availableNumbers) {
    int arrayToCheck[arrayLength] = zeroArray;
    for (int i = 0; i < arrayLength; ++i) {
        arrayToCheck[i] = sudoku[i][row];
    }
    CheckArrayGenerator(arrayToCheck, availableNumbers);

}

void CheckBoxGenerator(int sudoku[sudokuWidth][sudokuLength], int boxX, int boxY, int *availableNumbers) {
    int arrayToCheck[arrayLength] = zeroArray;
    int counter = 0;
    for (int i = 0; i < (sudokuLength / 3); ++i) {
        for (int j = 0; j < (sudokuWidth/3); ++j) {
            arrayToCheck[counter] = sudoku[boxX + i][boxY + j];
            counter = counter + 1;
        }
    }
    CheckArrayGenerator(arrayToCheck, availableNumbers);

}

void findCommonElements(int *arr1, int *arr2, int *arr3, int size1, int size2, int size3, int *validNumbers) {
    int counter = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            for (int k = 0; k < size3; k++) {
                if (arr1[i] == arr2[j] && arr1[i] == arr3[k]) {
                    validNumbers[counter] = arr1[i];
                    counter = counter + 1;
                    break;
                }
            }
        }
    }
}

int *CheckSudokuGenerator(int sudoku[sudokuLength][sudokuWidth], int x, int y, int *validNumbers) {
    int availableNumbersLine[arrayLength] = zeroArray;
    CheckLineGenerator(sudoku, x, availableNumbersLine);
    int availableNumbersRows[arrayLength] = zeroArray;
    CheckRowGenerator(sudoku, y, availableNumbersRows);

    int availableNumbersBox[arrayLength] = zeroArray;
    for (int i = 0; i < 7;) {
        for (int j = 0; j < 7;) {
            if (i == x && j == y) {
                CheckBoxGenerator(sudoku, i, j, availableNumbersBox);
            } else if (i == x && j + 1 == y) {
                CheckBoxGenerator(sudoku, i, j, availableNumbersBox);
            } else if (i == x && j + 2 == y) {
                CheckBoxGenerator(sudoku, i, j, availableNumbersBox);
            } else if (i + 1 == x && j == y) {
                CheckBoxGenerator(sudoku, i, j, availableNumbersBox);
            } else if (i + 1 == x && j + 1 == y) {
                CheckBoxGenerator(sudoku, i, j, availableNumbersBox);
            } else if (i + 1 == x && j + 2 == y) {
                CheckBoxGenerator(sudoku, i, j, availableNumbersBox);
            } else if (i + 2 == x && j == y) {
                CheckBoxGenerator(sudoku, i, j, availableNumbersBox);
            } else if (i + 2 == x && j + 1 == y) {
                CheckBoxGenerator(sudoku, i, j, availableNumbersBox);
            } else if (i + 2 == x && j + 2 == y) {
                CheckBoxGenerator(sudoku, i, j, availableNumbersBox);
            } else {
            }

            j = j + 3;

        }
        i = i + 3;
    }


    findCommonElements(availableNumbersLine, availableNumbersRows, availableNumbersBox, arrayLength, arrayLength, arrayLength, validNumbers);
    return validNumbers;
}

