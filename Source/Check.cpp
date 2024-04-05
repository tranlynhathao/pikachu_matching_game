#include "Check.h"

bool checkI(char** a, int x1, int y1, int x2, int y2)
{
	if (x1 == x2) // if same row
	{
		if (y1 > y2) // i want x1 y1 always in the left to only check 1 case
		{
			swap(y1, y2);
			swap(x1, x2);
		}
		for (int i = y1 + 1; i < y2; i++) // run from y1 to y2
		{
			if (a[x1][i] != ' ') // if have char return false
			{
				return false;
			}
		}
		return true;
	}
	if (y1 == y2) // if same col
	{
		if (x1 > x2) // i want x1 y1 always in the top to only check 1 case
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		for (int i = x1 + 1; i < x2; i++) // run x1 to x2 to check
		{
			if (a[i][y1] != ' ') // if have char return false
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
bool checkL(char** a, int x1, int y1, int x2, int y2)
{
	if ((x1 > x2 && y1 > y2) || (x1 < x2 && y1 < y2)) // 2 case have same position to have check 1 time
	{
		if (x1 > x2 && y1 > y2)// i want x1 y1 always the smaller than x2 y2 to check 1 case
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		if (checkI(a, x1, y1, x1, y2) && a[x1][y2] == ' ') // check I row from y1 to y2 and a[x1][y2] is blank or not
		{
			if (checkI(a, x1, y2, x2, y2)) // then if true check I from a[x1][y2] to a[x2][y2] if true so it have check L
			{
				return true;
			}
		}
		if (checkI(a, x1, y1, x2, y1) && a[x2][y1] == ' ')// check I col from x1 to x2 and a[x2][y1] is blank or not
		{
			if (checkI(a, x2, y1, x2, y2))// then if true check I from a[x2][y1] to a[x2][y2] if true so it have check L
			{
				return true;
			}
		}
		return false; // if 2 case is false return false
	}
	if ((x1 < x2 && y1 > y2) || (x1 > x2 && y1 < y2))// 2 case have same position to have check 1 times
	{
		if (x1 > x2 && y1 < y2) // i want x1 < x2 and y1 > y2 to check 1 times
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		if (checkI(a, x1, y1, x2, y1) && a[x2][y1] == ' ') // check I col a[x1][y1] to a[x2][y1] and a[x2][y1] blank or not
		{
			if (checkI(a, x2, y2, x2, y1)) // then if blank check a[x2][y2] to a[x2][y1] if true return true
			{
				return true;
			}
		}
		if (checkI(a, x1, y1, x1, y2) && a[x1][y2] == ' ') // check another L case with same idea
		{
			if (checkI(a, x2, y2, x1, y2))
			{
				return true;
			}
		}
		return false;
	}
	// if not in 2 case so it dont have check L
	return false;
}
bool checkZ(char** a, int x1, int y1, int x2, int y2)
{
	if ((x1 > x2 && y1 > y2) || (x1 < x2 && y1 < y2)) // 2 case can check 1 times
	{
		if (x1 > x2 && y1 > y2) // swap to have 1 check times
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		for (int i = y1 + 1; i < y2; i++)
		{
			if (a[x1][i] != ' ') // if have char this case is false
			{
				break;
			}
			if (checkL(a, x1, i, x2, y2)) // if blank check L to a[x2][y2] if true so it have check Z
			{
				return true;
			}
		}
		for (int i = x1 + 1; i < x2; i++)
		{
			if (a[i][y1] != ' ') // if have char this case is false
			{
				break;
			}
			if (checkL(a, i, y1, x2, y2)) // if blank check L to a[x2][y2] if true so it have check Z
			{
				return true;
			}
		}
		return false;
	}
	if ((x1 < x2 && y1 > y2) || (x1 > x2 && y1 < y2)) // 2 case can check 1 times
	{
		if (x1 > x2 && y1 < y2)// swap to have 1 check times
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		for (int i = x1 + 1; i < x2; i++)
		{
			if (a[i][y1] != ' ') // if have char this case is false
			{
				break;
			}
			if (checkL(a, i, y1, x2, y2)) // if blank check L to a[x2][y2] if true so it have check Z
			{
				return true;
			}
		}
		for (int i = y1 - 1; i > y2; i--)
		{
			if (a[x1][i] != ' ') // if have char this case is false
			{
				break;
			}
			if (checkL(a, x1, i, x2, y2)) // if blank check L to a[x2][y2] if true so it have check Z
			{
				return true;
			}
		}
		return false;
	}
	return false;
}
bool checkU(char** a, int x1, int y1, int x2, int y2)
{
	if (x1 == x2) // if have same row it have 2 U case check
	{
		for (int i = x1 - 1; i > -1; i--)
		{
			if (a[i][y1] != ' ') // if blank this case false
			{
				break;
			}
			if (checkL(a, i, y1, x2, y2)) // if have check L so it have check U
			{
				return true;
			}
		}
		for (int i = x1 + 1; i < 10; i++)
		{
			if (a[i][y1] != ' ') // if blank this case false
			{
				break;
			}
			if (checkL(a, i, y1, x2, y2)) // if have check L so it have check U
			{
				return true;
			}
		}
		return false;
	}
	if (y1 == y2) // if have same col it have 2 U case check
	{
		for (int i = y1 + 1; i < 10; i++)
		{
			if (a[x1][i] != ' ') // if blank break
			{
				break;
			}
			if (checkL(a, x1, i, x2, y2)) // if blank and have check L so it have check U
			{
				return true;
			}
		}
		for (int i = y1 - 1; i > -1; i--)
		{
			if (a[x1][i] != ' ') // if blank break
			{
				break;
			}
			if (checkL(a, x1, i, x2, y2)) // if blank and have check L so it have check U
			{
				return true;
			}
		}
		return false;
	}
	// i want x1 y1 always in the left to check 1 times
	if (y1 > y2)
	{
		swap(y1, y2);
		swap(x1, x2);
	}
	// check 4 U case
	for (int i = x1 - 1; i > -1; i--)
	{
		if (a[i][y1] != ' ')
		{
			break;
		}
		if (checkL(a, i, y1, x2, y2))
		{
			return true;
		}
	}
	for (int i = x1 + 1; i < 10; i++)
	{
		if (a[i][y1] != ' ')
		{
			break;
		}
		if (checkL(a, i, y1, x2, y2))
		{
			return true;
		}
	}
	for (int i = y1 + 1; i < 10; i++)
	{
		if (a[x1][i] != ' ')
		{
			break;
		}
		if (checkL(a, x1, i, x2, y2))
		{
			return true;
		}
	}
	for (int i = y1 - 1; i > -1; i--)
	{
		if (a[x1][i] != ' ')
		{
			break;
		}
		if (checkL(a, x1, i, x2, y2))
		{
			return true;
		}
	}
	return false;
}
bool checkValidPairs(char** a)
{
	// traversal all over the array to check a[i][j] with a[k][l] like bubble sort
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
						return true;
					}
					else if (checkZ(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						return true;
					}
					else if (checkL(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						return true;
					}
					else if (checkU(a, i, j, k, l) && (a[i][j] == a[k][l]) && !(i == k && j == l))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool checkEmpty(char** a)
{
	// traversal all over the array to check if have char return false
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] != ' ')
			{
				return false;
			}
		}
	}
	return true;
}