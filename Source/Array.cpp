#include "Array.h"

void randomArr(char** a)
{
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			int random = rand() % 64; // random 1 number from 0 to 63
			int row = random / 8 + 1; // convert to row and col
			int col = random % 8 + 1;
			swap(a[i][j], a[row][col]); // swap to have a random 2D array
		}
	}
}
void swapArr(char** a)
{
	for (int i = 1; i < 9; i++)
	{
		int count = 0; // count number of blank
		for (int k = 1; k < 9 - count; k++) // 9 - count means if have 1 blank code just run from 1 to 7
		{
			while (a[i][k] == ' ' && k < 9 - count) // if a[i][k] is blank swap with (last char - count) to move all the blank to end position
			{
				count++;
				swap(a[i][k], a[i][9 - count]);
			}
		}
	}
	int count = 0; // count number of row are blank
	for (int i = 1; i < 9 - count; i++)
	{
		bool check = true;
		while (check && i < 9 - count)
		{
			for (int k = 1; k < 9; k++)
			{
				if (a[i][k] != ' ') // check row a[i] have char or all blanks
				{
					check = false; // check until a[i] row have char to break this while loop
					break;
				}
			}
			if (check) // if true swap all row with last row
			{
				count++;
				if (i < 9 - count)
				{
					for (int l = 1; l < 9; l++)
					{
						swap(a[i][l], a[9 - count][l]);
					}
				}
			}
		}
	}
}
void gen2D(char** a)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			a[i][j] = ' '; // set all char is blank
		}
	}
	int temptemp = 1; // A B C D E F G // A 10 B 10 C 10 D 10 E 8 F 8 G 8 = 64
	// set up array with A to G continuous
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (temptemp <= 10) // 10 first is A
			{
				a[i][j] = 'A';
				temptemp++;
			}
			else if (temptemp <= 20) // 10 after is B
			{
				a[i][j] = 'B';
				temptemp++;
			}
			else if (temptemp <= 30)
			{
				a[i][j] = 'C';
				temptemp++;
			}
			else if (temptemp <= 40)
			{
				a[i][j] = 'D';
				temptemp++;
			}
			else if (temptemp <= 48)
			{
				a[i][j] = 'E';
				temptemp++;
			}
			else if (temptemp <= 56)
			{
				a[i][j] = 'F';
				temptemp++;
			}
			else if (temptemp <= 64)
			{
				a[i][j] = 'G';
				temptemp++;
			}
		}
	}
	// random swap all char to have random array
	randomArr(a);
}