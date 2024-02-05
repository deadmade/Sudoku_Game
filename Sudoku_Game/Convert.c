#include <ctype.h>

int ConvertChartoInt(int character)
{
	switch (character)
	{
	case 48:
		return 0;
	case 49:
		return 1;
	case 50:
		return 2;
	case 51:
		return 3;
	case 52:
		return 4;
	case 53:
		return 5;
	case 54:
		return 6;
	case 55:
		return 7;
	case 56:
		return 8;
	case 57:
		return 9;
	default:
		return -1;
	}
}

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

int ConvertCounter(int counter, int direction)
{
	if (direction == 1)
	{
		if (counter +1 == 10)
		{
			return 0;
		}
		else
		{
			return counter + 1;
		}
	}
	else
	{
		if (counter  == 0)
		{
			return 9;
		}
		else
		{
			return counter - 1;
		}
	}
}