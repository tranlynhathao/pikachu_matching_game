#include "Move Suggest and Delete.h"

void deleteSuggestion(char** a)
{
	// traversal all over the array and check a[i][j] with a[k][l] if true, delete and return
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] == ' ')
			{
				continue;
			}
			int k = i;
			int l = j + 1;
			if (j == 8)
			{
				l = 0;
				k = i + 1;
			}
			for (; k < 9; k++)
			{
				l = 1;
				for (; l < 9; l++)
				{
					if (checkI(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						a[i][j] = ' ';
						a[k][l] = ' ';
						return;
					}
					else if (checkZ(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						a[i][j] = ' ';
						a[k][l] = ' ';
						return;
					}
					else if (checkL(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						a[i][j] = ' ';
						a[k][l] = ' ';
						return;
					}
					else if (checkU(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						a[i][j] = ' ';
						a[k][l] = ' ';
						return;
					}

				}
			}
		}
	}
}
void moveSuggestion(char** a, int x, int y)
{
	// traversal all over the array and check a[i][j] with a[k][l] if true, draw white color and return
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] == ' ')
			{
				continue;
			}
			int k = i;
			int l = j + 1;
			if (j == 8)
			{
				l = 0;
				k = i + 1;
			}
			for (; k < 9; k++)
			{
				l = 1;
				for (; l < 9; l++)
				{
					if (checkI(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						repBoard(a, 10, 10, x, y, i, j, k, l);
						return;
					}
					else if (checkZ(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						repBoard(a, 10, 10, x, y, i, j, k, l);
						return;
					}
					else if (checkL(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						repBoard(a, 10, 10, x, y, i, j, k, l);
						return;
					}
					else if (checkU(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						repBoard(a, 10, 10, x, y, i, j, k, l);
						return;
					}
				}
			}
		}
	}
}
void moveSuggestionHidden(char** a, int x, int y)
{
	// traversal all over the array and check a[i][j] with a[k][l] if true, draw white color and return
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] == ' ')
			{
				continue;
			}
			int k = i;
			int l = j + 1;
			if (j == 8)
			{
				l = 0;
				k = i + 1;
			}
			for (; k < 9; k++)
			{
				l = 1;
				for (; l < 9; l++)
				{
					if (checkI(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						repBoardHidden(a, 10, 10, x, y, i, j, k, l);
						return;
					}
					else if (checkZ(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						repBoardHidden(a, 10, 10, x, y, i, j, k, l);
						return;
					}
					else if (checkL(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						repBoardHidden(a, 10, 10, x, y, i, j, k, l);
						return;
					}
					else if (checkU(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						repBoardHidden(a, 10, 10, x, y, i, j, k, l);
						return;
					}
				}
			}
		}
	}
}