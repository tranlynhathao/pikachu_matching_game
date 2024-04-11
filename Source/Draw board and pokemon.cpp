#include "Draw board and pokemon.h"

void set_color(int code) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}
void repColor(char c) {// ham bieu dien mau tuy vao o
	switch (c)
	{
	case 'A':
	{
		set_color(0x01);
		break;
	}
	case 'B':
	{
		set_color(0x02);
		break;
	}
	case 'C':
	{
		set_color(0x0E);
		break;
	}
	case 'D':
	{
		set_color(0x04);
		break;
	}
	case 'E':
	{
		set_color(0x05);
		break;
	}
	case 'F':
	{
		set_color(0x06);
		break;
	}
	case 'G':
	{
		set_color(0x0B);
		break;
	}
	};
}
void repBoard(char** a, int m, int n, int px, int py, int x1, int y1, int x2, int y2)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); // draw color
	SetConsoleTextAttribute(color, 0x0C);
	cout << "  ";
	bool check = false;
	for (int i = 1; i < 9; i++)
	{
		if (i == 1 || i == 2) // draw W A S D R F button in the right
		{
			check = true;
		}
		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] != ' ')
			{
				repColor(a[i][j]);
				cout << " ------- ";
			}
			if (a[i][j] == ' ')
				cout << "         ";
		}
		// draw W A S D R F button in the right
		SetConsoleTextAttribute(color, 0x0C);
		cout << "         ";
		if (check && i == 1)
		{
			cout << "         " << "         " << " ------- " << "         " << "         " << " ------- ";
		}
		else if (check)
		{
			cout << "         " << " ------- " << " ------- " << " ------- " << "         " << " ------- ";
		}
		SetConsoleTextAttribute(color, 0x06);
		if (i == 3)
		{
			cout << "         " << "                   _,..-----+-\".\".-'_,..";
		}
		if (i == 4)
		{
			cout << "         " << "      |  /,----._           ,.----.       .";
		}
		if (i == 5)
		{
			cout << "         " << "j       | ,-\"'    `    .'         `. `        `.";
		}
		if (i == 6)
		{
			cout << "         " << " \\       /                      `.    |              .";
		}
		if (i == 7)
		{
			cout << "         " << ".     .                         .'         `.__,.',.----,";
		}
		if (i == 8)
		{
			cout << "         " << " \\                                          /   ,'";
		}

		cout << endl << "  ";

		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] != ' ')
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
					cout << "|";
					set_color(0x70);
					cout << "       ";
					repColor(a[i][j]);
					cout << "|";
				}
				else
				{
					repColor(a[i][j]);
					cout << "|       |";
				}
			}
			else
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					cout << " ";
					set_color(0x70);
					cout << "       ";
					set_color(0x07);
					cout << " ";
				}
				else
					cout << "         ";
			}
		}
		// draw W A S D R F button in the right
		SetConsoleTextAttribute(color, 0x0C);
		cout << "         ";
		if (check && i == 1)
		{
			cout << "         " << "         " << "|" << "       " << "|" << "         " << "         " << "|" << "       " << "|";
		}
		else if (check)
		{
			cout << "         " << "|" << "       " << "|" << "|" << "       " << "|" << "|" << "       " << "|" << "         " << "|" << "       " << "|";
		}
		SetConsoleTextAttribute(color, 0x06);
		if (i == 3)
		{
			cout << "         " << "           ,...,.\"'             `--.---'";
		}
		if (i == 4)
		{
			cout << "         " << "     ,  j    _   \\        .'  .,   `.     |";
		}
		if (i == 5)
		{
			cout << "         " << "|        .\\                        /  |         \\";
		}
		if (i == 6)
		{
			cout << "         " << "  ` /  ,'                        |    `              |";
		}
		if (i == 7)
		{
			cout << "         " << "|      `.                     ,'             .-\"\"      /";
		}
		if (i == 8)
		{
			cout << "         " << "  \\                                        /  ,'";
		}

		cout << endl << "  ";
		SetConsoleTextAttribute(color, 0x07);

		for (int j = 1; j < 9; j++)
		{
			if (j == 0)
			{
				set_color(0x07);
			}
			if (a[i][j] != ' ')
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
					cout << "|";
					set_color(0x70);
					cout << "   " << a[i][j] << "   ";
					repColor(a[i][j]);
					cout << "|";
				}
				else
				{
					repColor(a[i][j]);
					cout << "|   " << a[i][j] << "   |";
				}
			}
			else
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					cout << " ";
					set_color(0x70);
					cout << "       ";
					set_color(0x07);
					cout << " ";
				}
				else
					cout << "         ";
			}
		}
		// draw W A S D R F button in the right
		SetConsoleTextAttribute(color, 0x0C);
		cout << "         ";
		if (check && i == 1)
		{
			cout << "         " << "         " << "|" << "   W   " << "|" << "         " << "         " << "|" << "   R   " << "|";
		}
		else if (check)
		{
			cout << "         " << "|" << "   A   " << "|" << "|" << "   S   " << "|" << "|" << "   D   " << "|" << "         " << "|" << "   F   " << "|";
		}
		SetConsoleTextAttribute(color, 0x06);
		if (i == 3)
		{
			cout << "         " << "         /,..,'                     `.";
		}
		if (i == 4)
		{
			cout << "         " << "   ,'   |        |  ____  |         | .\"--+,^.";
		}
		if (i == 5)
		{
			cout << "         " << "|         `\\                     ,'   |          \\";
		}
		if (i == 6)
		{
			cout << "         " << "   /  /                          |     \\             |";
		}
		if (i == 7)
		{
			cout << "         " << "|        `._               _.'               |        /";
		}
		if (i == 8)
		{
			cout << "         " << "   \\                                      / ,'";
		}

		cout << endl << "  ";

		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] != ' ')
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
					cout << "|";
					set_color(0x70);
					cout << "       ";
					repColor(a[i][j]);
					cout << "|";
				}
				else
				{
					repColor(a[i][j]);
					cout << "|       |";
				}
			}
			else
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					cout << " ";
					set_color(0x70);
					cout << "       ";
					set_color(0x07);
					cout << " ";
				}
				else
					cout << "         ";
			}
		}

		// draw W A S D R F button in the right
		SetConsoleTextAttribute(color, 0x0C);
		cout << "         ";
		if (check && i == 1)
		{
			cout << "         " << "         " << "|" << "       " << "|" << "         " << "         " << "|" << "       " << "|";
		}
		else if (check)
		{
			cout << "         " << "|" << "       " << "|" << "|" << "       " << "|" << "|" << "       " << "|" << "         " << "|" << "       " << "|";
		}
		SetConsoleTextAttribute(color, 0x06);
		if (i == 3)
		{
			cout << "         " << "       ,'  .'                         `.";
		}
		if (i == 4)
		{
			cout << "         " << "  /     |`-....-',-'    `._`--....-' _/      |";
		}
		if (i == 5)
		{
			cout << "         " << "|          |                    |   ,-|           `.";
		}
		if (i == 6)
		{
			cout << "         " << "  /  |                           |      \\           /";
		}
		if (i == 7)
		{
			cout << "         " << "|           `---.......,--\"                  |      ,'";
		}
		if (i == 8)
		{
			cout << "         " << "    `.                                   ,+'";
		}

		cout << endl << "  ";

		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] != ' ')
			{
				repColor(a[i][j]);
				cout << " ------- ";
			}
			if (a[i][j] == ' ')
				cout << "         ";
		}
		// draw W A S D R F button in the right
		SetConsoleTextAttribute(color, 0x0C);
		cout << "         ";
		if (check && i == 1)
		{
			cout << "         " << "         " << " ------- " << "         " << "         " << " ------- ";
		}
		else if (check)
		{
			cout << "         " << " ------- " << " ------- " << " ------- " << "         " << " ------- ";
		}
		SetConsoleTextAttribute(color, 0x06);
		if (i == 3)
		{
			cout << "         " << "      j   /                             `.";
		}
		if (i == 4)
		{
			cout << "         " << " /      |     _,'          `--..__  `        '";
		}
		if (i == 5)
		{
			cout << "         " << ".         ,'                    |-\"'  |             \\";
		}
		if (i == 6)
		{
			cout << "         " << " /   |                           |       `.       _,";
		}
		if (i == 7)
		{
			cout << "         " << "'                                            '    ,'";
		}
		if (i == 8)
		{
			cout << "         " << "      >._______________________________,'";
			//cout << "         " << "      >.                               ,'";
		}

		cout << endl << "  ";
		set_color(0x07);
		check = false;
	}
}
void repBoardHidden(char** a, int m, int n, int px, int py, int x1, int y1, int x2, int y2)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); // draw color
	SetConsoleTextAttribute(color, 0x0C);
	cout << "  ";
	bool check = false;
	for (int i = 1; i < 9; i++)
	{
		if (i == 1 || i == 2) // draw W A S D R F button in the right
		{
			check = true;
		}
		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] != ' ') // draw all white only draw color with x1, x2
			{
				if ((i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
				}
				else
				{
					SetConsoleTextAttribute(color, 0x07);
				}
				cout << " ------- ";
			}
			if (a[i][j] == ' ')
				cout << "         ";
		}
		// draw W A S D R F button in the right
		SetConsoleTextAttribute(color, 0x0C);
		cout << "         ";
		if (check && i == 1)
		{
			cout << "         " << "         " << " ------- " << "         " << "         " << " ------- ";
		}
		else if (check)
		{
			cout << "         " << " ------- " << " ------- " << " ------- " << "         " << " ------- ";
		}
		SetConsoleTextAttribute(color, 0x06);
		if (i == 3)
		{
			cout << "         " << "                   _,..-----+-\".\".-'_,..";
		}
		if (i == 4)
		{
			cout << "         " << "      |  /,----._           ,.----.       .";
		}
		if (i == 5)
		{
			cout << "         " << "j       | ,-\"'    `    .'         `. `        `.";
		}
		if (i == 6)
		{
			cout << "         " << " \\       /                      `.    |              .";
		}
		if (i == 7)
		{
			cout << "         " << ".     .                         .'         `.__,.',.----,";
		}
		if (i == 8)
		{
			cout << "         " << " \\                                          /   ,'";
		}

		cout << endl << "  ";

		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] != ' ')// draw all white only draw color with x1, x2
			{
				if ((i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
					cout << "|";
					set_color(0x70);
					cout << "       ";
					repColor(a[i][j]);
					cout << "|";
				}
				else
				{
					SetConsoleTextAttribute(color, 0x07);
					cout << "|";
					if (i == px && j == py)
					{
						SetConsoleTextAttribute(color, 0x70);
					}
					else
						SetConsoleTextAttribute(color, 0x07);
					cout << "       ";
					SetConsoleTextAttribute(color, 0x07);
					cout << "|";
				}
			}
			else
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					cout << " ";
					set_color(0x70);
					cout << "       ";
					set_color(0x07);
					cout << " ";
				}
				else
					cout << "         ";
			}
		}
		// draw W A S D R F button in the right
		SetConsoleTextAttribute(color, 0x0C);
		cout << "         ";
		if (check && i == 1)
		{
			cout << "         " << "         " << "|" << "       " << "|" << "         " << "         " << "|" << "       " << "|";
		}
		else if (check)
		{
			cout << "         " << "|" << "       " << "|" << "|" << "       " << "|" << "|" << "       " << "|" << "         " << "|" << "       " << "|";
		}
		SetConsoleTextAttribute(color, 0x06);
		if (i == 3)
		{
			cout << "         " << "           ,...,.\"'             `--.---'";
		}
		if (i == 4)
		{
			cout << "         " << "     ,  j    _   \\        .'  .,   `.     |";
		}
		if (i == 5)
		{
			cout << "         " << "|        .\\                        /  |         \\";
		}
		if (i == 6)
		{
			cout << "         " << "  ` /  ,'                        |    `              |";
		}
		if (i == 7)
		{
			cout << "         " << "|      `.                     ,'             .-\"\"      /";
		}
		if (i == 8)
		{
			cout << "         " << "  \\                                        /  ,'";
		}

		cout << endl << "  ";
		SetConsoleTextAttribute(color, 0x07);

		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] != ' ')// draw all white only draw color with x1, x2
			{
				if ((i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
					cout << "|";
					set_color(0x70);
					cout << "   " << a[i][j] << "   ";
					repColor(a[i][j]);
					cout << "|";
				}
				else
				{
					SetConsoleTextAttribute(color, 0x07);
					cout << "|";
					if (i == px && j == py)
					{
						SetConsoleTextAttribute(color, 0x70);
					}
					else
						SetConsoleTextAttribute(color, 0x07);
					cout << "       ";
					SetConsoleTextAttribute(color, 0x07);
					cout << "|";
				}
			}
			else
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					cout << " ";
					set_color(0x70);
					cout << "       ";
					set_color(0x07);
					cout << " ";
				}
				else
					cout << "         ";
			}
		}
		// draw W A S D R F button in the right
		SetConsoleTextAttribute(color, 0x0C);
		cout << "         ";
		if (check && i == 1)
		{
			cout << "         " << "         " << "|" << "   W   " << "|" << "         " << "         " << "|" << "   R   " << "|";
		}
		else if (check)
		{
			cout << "         " << "|" << "   A   " << "|" << "|" << "   S   " << "|" << "|" << "   D   " << "|" << "         " << "|" << "   F   " << "|";
		}
		SetConsoleTextAttribute(color, 0x06);
		if (i == 3)
		{
			cout << "         " << "         /,..,'                     `.";
		}
		if (i == 4)
		{
			cout << "         " << "   ,'   |        |  ____  |         | .\"--+,^.";
		}
		if (i == 5)
		{
			cout << "         " << "|         `\\                     ,'   |          \\";
		}
		if (i == 6)
		{
			cout << "         " << "   /  /                          |     \\             |";
		}
		if (i == 7)
		{
			cout << "         " << "|        `._               _.'               |        /";
		}
		if (i == 8)
		{
			cout << "         " << "   \\                                      / ,'";
		}

		cout << endl << "  ";

		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] != ' ')// draw all white only draw color with x1, x2
			{
				if ((i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
					cout << "|";
					set_color(0x70);
					cout << "       ";
					repColor(a[i][j]);
					cout << "|";
				}
				else
				{
					SetConsoleTextAttribute(color, 0x07);
					cout << "|";
					if (i == px && j == py)
					{
						SetConsoleTextAttribute(color, 0x70);
					}
					else
						SetConsoleTextAttribute(color, 0x07);
					cout << "       ";
					SetConsoleTextAttribute(color, 0x07);
					cout << "|";
				}
			}
			else
			{
				if ((i == px && j == py) || (i == x1 && j == y1) || (i == x2 && j == y2))
				{
					cout << " ";
					set_color(0x70);
					cout << "       ";
					set_color(0x07);
					cout << " ";
				}
				else
					cout << "         ";
			}
		}

		// draw W A S D R F button in the right
		SetConsoleTextAttribute(color, 0x0C);
		cout << "         ";
		if (check && i == 1)
		{
			cout << "         " << "         " << "|" << "       " << "|" << "         " << "         " << "|" << "       " << "|";
		}
		else if (check)
		{
			cout << "         " << "|" << "       " << "|" << "|" << "       " << "|" << "|" << "       " << "|" << "         " << "|" << "       " << "|";
		}
		SetConsoleTextAttribute(color, 0x06);
		if (i == 3)
		{
			cout << "         " << "       ,'  .'                         `.";
		}
		if (i == 4)
		{
			cout << "         " << "  /     |`-....-',-'    `._`--....-' _/      |";
		}
		if (i == 5)
		{
			cout << "         " << "|          |                    |   ,-|           `.";
		}
		if (i == 6)
		{
			cout << "         " << "  /  |                           |      \\           /";
		}
		if (i == 7)
		{
			cout << "         " << "|           `---.......,--\"                  |      ,'";
		}
		if (i == 8)
		{
			cout << "         " << "    `.                                   ,+'";
		}

		cout << endl << "  ";

		for (int j = 1; j < 9; j++)
		{
			if (a[i][j] != ' ')// draw all white only draw color with x1, x2, y1, y2
			{
				if ((i == x1 && j == y1) || (i == x2 && j == y2))
				{
					repColor(a[i][j]);
				}
				else
				{
					SetConsoleTextAttribute(color, 0x07);
				}
				cout << " ------- ";
			}
			if (a[i][j] == ' ')
				cout << "         ";
		}
		SetConsoleTextAttribute(color, 0x0C);
		cout << "         ";
		if (check && i == 1)
		{
			cout << "         " << "         " << " ------- " << "         " << "         " << " ------- ";
		}
		else if (check)
		{
			cout << "         " << " ------- " << " ------- " << " ------- " << "         " << " ------- ";
		}
		SetConsoleTextAttribute(color, 0x06);
		if (i == 3)
		{
			cout << "         " << "      j   /                             `.";
		}
		if (i == 4)
		{
			cout << "         " << " /      |     _,'          `--..__  `        '";
		}
		if (i == 5)
		{
			cout << "         " << ".         ,'                    |-\"'  |             \\";
		}
		if (i == 6)
		{
			cout << "         " << " /   |                           |       `.       _,";
		}
		if (i == 7)
		{
			cout << "         " << "'                                            '    ,'";
		}
		if (i == 8)
		{
			cout << "         " << "      >._______________________________,'";
			//cout << "         " << "      >.                               ,'";
		}

		cout << endl << "  ";
		set_color(0x07);
		check = false;
	}
}
void print_pokemon(int n_pokemon)
{
	// print menu and pokemon
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (n_pokemon) 
	{
	case 1:
	{
		SetConsoleTextAttribute(color, 0x70);
		cout << ">> 1. Play normal mode <<";
		SetConsoleTextAttribute(color, 0x02);
		cout << "                             ";
		printf("                                           /\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "2. Play hard mode" << "                                     ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                        _,.------....___,.' ',.-.\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "3. Play fun mode" << "                                      ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                     ,-'          _,.--\"        |\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "4. Play hidden mode" << "                                   ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                   ,'         _.-'              .\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "5. Show All Player Score" << "                              ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                  /   ,     ,'                   `\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "6. Exit Game" << "                                          ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                 .   /     /                     ``.\n");
		cout << "                                                      ";
		printf("                 |  |     .                       \\.\\\n");
		cout << "                                                      ";
		printf("       ____      |___._.  |       __               \\ `.\n");
		cout << "                                                      ";
		printf("     .'    `---\"\"       ``\"-.--\"'`  \\               .  \\\n");
		cout << "                                                      ";
		printf("    .  ,            __               `              |   .\n");
		cout << "                                                      ";
		printf("    `,'         ,-\"'  .               \\             |    L\n");
		cout << "                                                      ";
		printf("   ,'          '    _.'                -._          /    |\n");
		cout << "                                                      ";
		printf("  ,`-.    ,\".   `--'                      >.      ,'     |\n");
		cout << "                                                      ";
		printf(" . .'\\'   `-'       __    ,  ,-.         /  `.__.-      ,'\n");
		cout << "                                                      ";
		printf(" ||:, .           ,'  ;  /  / \\ `        `.    .      .'/\n");
		cout << "                                                      ";
		printf(" j|:D  \\          `--'  ' ,'_  . .         `.__, \\   , /\n");
		cout << "                                                      ";
		printf("/ L:_  |                 .  \"' :_;                `.'.'\n");
		cout << "                                                      ";
		printf(".    \"\"'                  \"\"\"\"\"'                    V\n");
		cout << "                                                      ";
		printf(" `.                                 .    `.   _,..  `\n");
		cout << "                                                      ";
		printf("   `,_   .    .                _,-'/    .. `,'   __  `\n");
		cout << "                                                      ";
		printf("    ) \\`._        ___....----\"'  ,'   .'  \\ |   '  \\  .\n");
		cout << "                                                      ";
		printf("   /   `. \"`-.--\"'         _,' ,'     `---' |    `./  |\n");
		cout << "                                                      ";
		printf("  .   _  `\"\"'--.._____..--\"   ,             '         |\n");
		cout << "                                                      ";
		printf("  | .\" `. `-.                /-.           /          ,\n");
		cout << "                                                      ";
		printf("  | `._.'    `,_            ;  /         ,'          .\n");
		cout << "                                                      ";
		printf(" .'          /| `-.        . ,'         ,           ,\n");
		cout << "                                                      ";
		printf(" '-.__ __ _,','    '`-..___;-...__   ,.'\\ ____.___.'\n");
		cout << "                                                      ";
		printf(" `\"^--'..'   '-`-^-'\"--    `-^-'`.''\"\"\"\"\"`.,^.`.--' mh\n");

		break;
	}

	case 2:
	{
		SetConsoleTextAttribute(color, 0x07);
		cout << "1. Play normal mode" << "                                   ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                               ,'\"`.,./.\n");
		SetConsoleTextAttribute(color, 0x70);
		cout << ">> 2. Play hard mode <<";
		SetConsoleTextAttribute(color, 0x02);
		cout << "                               ";
		printf("                             ,'        Y',\"..\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "3. Play fun mode" << "                                      ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                           ,'           \\  | \\\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "4. Play hidden mode" << "                                   ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                          /              . |  `\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "5. Show All Player Score" << "                              ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                         /               | |   \\\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "6. Exit Game" << "                                          ";
		SetConsoleTextAttribute(color, 0x02);
		printf("            __          .                | |    .\n");
		cout << "                                                      ";
		printf("       _   \\  `. ---.   |                | j    |\n");
		cout << "                                                      ";
		printf("      / `-._\\   `Y   \\  |                |.     |\n");
		cout << "                                                      ";
		printf("     _`.    ``    \\   \\ |..              '      |,-'\"\"7,....\n");
		cout << "                                                      ";
		printf("     l     '-.     . , `|  | , |`. , ,  /,     ,'    '/   ,'_,.-.\n");
		cout << "                                                      ";
		printf("     `-..     `-.  : :     |/ `   ' \"\\,' | _  /          '-'    /___\n");
		cout << "                                                      ";
		printf("      \\\"\"' __.,.-`.: :        /   /._    l'.,'\n");
		cout << "                                                      ";
		printf("       `--,   _.-' `\".           /__ `'-.' '         .\n");
		cout << "                                                      ";
		printf("       ,---..._,.--\"\"\"\"\"\"\"--.__..----,-.'   .  /    .'   ,.--\n");
		cout << "                                                      ";
		printf("       |                          ,':| /    | /     ;.,-'--      ,.-\n");
		cout << "                                                      ";
		printf("       |     .---.              .'  :|'     |/ ,.-='\"-.`\"`' _   -.'\n");
		cout << "                                                      ";
		printf("       /    \\    /               `. :|--.  _L,\"---.._        \"----'\n");
		cout << "                                                      ";
		printf("     ,' `.   \\ ,'           _,     `''   ``.-'       `-  -..___,'\n");
		cout << "                                                      ";
		printf("    . ,.  .   `   __     .-'  _.-           `.     .__    \\\n");
		cout << "                                                      ";
		printf("    |. |`        \"  ;   !   ,.  |             `.    `.`'---'\n");
		cout << "                                                      ";
		printf("    ,| |C\\       ` /    | ,' |(]|            -. |-..--`\n");
		cout << "                                                      ";
		printf("   /  \"'--'       '      /___|__]        `.  `- |`.\n");
		cout << "                                                      ";
		printf("  .       ,'                   ,   /       .    `. \\\n");
		cout << "                                                      ";
		printf("    \\                      .,-'  ,'         .     `-.\n");
		cout << "                                                      ";
		printf("     x---..`.  -'  __..--'\"/\"\"\"\"\"  ,-.      |   |   |\n");
		cout << "                                                      ";
		printf("    / \\--._'-.,.--'     _`-    _. ' /       |     -.|\n");
		cout << "                                                      ";
		printf("   ,   .   `-..__ ...--'  _,.-' | `   ,.-.  ;   /  '|\n");
		cout << "                                                      ";
		printf("  .  _,'         '\"-----\"\"      |    `   | /  ,'    ;\n");
		cout << "                                                      ";
		printf("  |-'  .-.    `._               |     `._// ,'     /\n");
		cout << "                                                      ";
		printf(" _|    `-'   _,' \"`--.._________|        `,'    _ /.\n");
		cout << "                                                      ";
		printf("//\\   ,-._.'\"/\\__,.   _,\"     /_\\__/`. /'.-.'.-/_,`-' mh\n");
		cout << "                                                      ";
		printf("`-\"`\"' v'    `\"  `-`-\"              `-'`-`  `'\n");

		break;
	}

	case 3:
	{
		SetConsoleTextAttribute(color, 0x07);
		cout << "1. Play normal mode" << "                                   ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                           _._       _,._\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "2. Play hard mode" << "                                     ";
		SetConsoleTextAttribute(color, 0x02);
		printf("                        _.'   `. ' .'   _`.\n");
		SetConsoleTextAttribute(color, 0x70);
		cout << ">> 3. Play fun mode <<";
		SetConsoleTextAttribute(color, 0x02);
		cout << "                                ";
		printf("                ,\"\"\"/`\"\"-.-.,/. ` V'\\-,`.,--/\"\"\".\"-..\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "4. Play hidden mode" << "                                   ";
		SetConsoleTextAttribute(color, 0x02);
		printf("              ,'    `...,' . ,\\-----._|     `.   /   \\\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "5. Show All Player Score" << "                              ";
		SetConsoleTextAttribute(color, 0x02);
		printf("             `.            .`  -'`\"\" .._   :> `-'   `.\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "6. Exit Game" << "                                          ";
		SetConsoleTextAttribute(color, 0x02);
		printf("            ,'  ,-.  _,.-'| `..___ ,'   |'-..__   .._ L\n");
		cout << "                                                      ";
		printf("           .    \\_ -'   `-'     ..      `.-' `.`-.'_ .|\n");
		cout << "                                                      ";
		printf("           |   ,',-,--..  ,--../  `.  .-.    , `-.  ``.\n");
		cout << "                                                      ";
		printf("           `.,' ,  |   |  `.  /'/,,.\\/  |    \\|   |\n");
		cout << "                                                      ";
		printf("                `  `---'    `j   .   \\  .     '   j\n");
		cout << "                                                      ";
		printf("              ,__`\"        ,'|`'\\_/`.'\\'        |\\-'-, _,.\n");
		cout << "                                                      ";
		printf("       .--...`-. `-`. /    '- ..      _,    /\\ ,' .--\"'  ,'\".\n");
		cout << "                                                      ";
		printf("     _'-\"\"-    --  _`'-.../ __ '.'`-^,_`-\"\"\"\"---....__  ' _,-`\n");
		cout << "                                                      ";
		printf("   _.----`  _..--.'        |  \"`-..-\" __|'\"'         .\"\"-. \"\"'--.._\n");
		cout << "                                                      ";
		printf("  /        '    /     ,  _.+-.'  ||._'   \"\"\"\". .          `     .__\\\n");
		cout << "                                                      ";
		printf(" `---    /        /  / j'       _/|..`  -. `-`\\ \\   \\  \\   `.  \\ `-..\n");
		cout << "                                                      ";
		printf(",\" _.-' /    /` ./  /`_|_,-\"   ','|       `. | -'`._,   L  \\ .  `.   |\n");
		cout << "                                                      ";
		printf("`\"' /  /  / ,__...-----| _.,  ,'            `|----.._`-.|' |. .` ..  .\n");
		cout << "                                                      ";
		printf("   /  '| /.,/   \\--.._ `-,' ,          .  '`.'  __,., '  ''``._ \\ \\`,'\n");
		cout << "                                                      ";
		printf("  /_,'---  ,     \\`._,-` \\ //  / . \\    `._,  -`,  / / _   |   `-L -\n");
		cout << "                                                      ";
		printf("   /       `.     ,  ..._ ' `_/ '| |\\ `._'       '-.'   `.,'     |\n");
		cout << "                                                      ";
		printf("  '         /    /  ..   `.  `./ | ; `.'    ,\"\" ,.  `.    \\      |\n");
		cout << "                                                      ";
		printf("   `.     ,'   ,'   | |\\  |       \"        |  ,'\\ |   \\    `    ,L\n");
		cout << "                                                      ";
		printf("   /|`.  /    '     | `-| '                  /`-' |    L    `._/  \\\n");
		cout << "                                                      ";
		printf("  / | .`|    |  .   `._.'                   `.__,'   .  |     |  (`\n");
		cout << "                                                      ";
		printf(" '-\"\"-'_|    `. `.__,._____     .    _,        ____ ,-  j     \".-'\"'\n");
		cout << "                                                      ";
		printf("        \\      `-.  \\/.    `\"--.._    _,.---'\"\"\\/  \"_,.'     /-'\n");
		cout << "                                                      ";
		printf("         )        `-._ '-.        `--\"      _.-'.-\"\"        `.\n");
		cout << "                                                      ";
		printf("        ./            `,. `\".._________...\"\"_.-\"`.          _j\n");
		cout << "                                                      ";
		printf("       /_\\.__,\"\".   ,.'  \"`-...________.---\"     .\".   ,.  / \\\n");
		cout << "                                                      ";
		printf("              \\_/\"\"\"-'                           `-'--(_,`\"`-` mh\n");

		break;
	}

	case 4:
	{
		SetConsoleTextAttribute(color, 0x07);
		cout << "1. Play normal mode" << "                                     ";
		SetConsoleTextAttribute(color, 0x05);
		printf("                    __.._\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "2. Play hard mode" << "                                       ";
		SetConsoleTextAttribute(color, 0x05);
		printf("                ,--'     \"`-._    _,.-,--------.\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "3. Play fun mode" << "                                        ";
		SetConsoleTextAttribute(color, 0x05);
		printf("    ________ ,-'              `-\"'   /     _.-'|\n");
		SetConsoleTextAttribute(color, 0x70);
		cout << ">> 4. Play hidden mode <<";
		SetConsoleTextAttribute(color, 0x05);
		cout << "                               |";
		printf(" ,-'  '     :                       .    ,'    '\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "5. Show All Player Score" << "                                ";
		SetConsoleTextAttribute(color, 0x05);
		printf("|    '     j      _.._              |  ,'     j\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "6. Exit Game" << "                                            ";
		SetConsoleTextAttribute(color, 0x05);
		printf("L   /      |    .'    `.            |.'      /\n");
		cout << "                                                        ";
		printf(" \\ j       |    `.,'   |           ,'       /    _\n");
		cout << "                                                        ";
		printf("  .|      ,'\\         /           '.___    / _.-\" |\n");
		cout << "                                                        ";
		printf("   `    .'   `-.....-'                 `- +-'    /\n");
		cout << "                                                        ";
		printf("    `. ,'                                `.     <__\n");
		cout << "                                                        ";
		printf("      `.             .\\ \\                 |   ___ ,'\n");
		cout << "                                                        ";
		printf("      |     | #      || |                  ,\"\"   \"`.\n");
		cout << "                                                        ";
		printf("      |     | #      `'_/                   .       `.\n");
		cout << "                                                        ";
		printf("     ,'     `.         ,-\"\".                L         `.\n");
		cout << "                                                        ";
		printf("    /     (__)       _  \"\"\"                  :\"\"-.      .\n");
		cout << "                                                        ";
		printf("   /             \\\"'u|         |/            |    \\     |\n");
		cout << "                                                        ";
		printf("  .               \\  |         |           | |     |    |\n");
		cout << "                                                        ";
		printf("  |     _          `-'        j           /  |     '    |\n");
		cout << "                                                        ";
		printf("  L      `.                   |          /   |   ,'     '\n");
		cout << "                                                        ";
		printf("   \\       `.                ,'         /    |_,'      /\n");
		cout << "                                                        ";
		printf("    `.   ,.<'                `+--.    ,'     /       ,'\n");
		cout << "                                                        ";
		printf("      `./`._'                 '_.`._,'      j      _,\n");
		cout << "                                                        ";
		printf("        /\"'                      \"          |   _,'\n");
		cout << "                                                        ";
		printf("       /   `._              .              '..-'\n");
		cout << "                                                        ";
		printf("      j       `-._           `            /\n");
		cout << "                                                        ";
		printf("      |        _,'`\"--........+.         /\n");
		cout << "                                                        ";
		printf("      ,\"-.._,-'                 `.  .-._/\n");
		cout << "                                                        ";
		printf("      '---'                       `+__,' mh\n");

		break;
	}

	case 5:
	{
		SetConsoleTextAttribute(color, 0x07);
		cout << "1. Play normal mode" << "                                   ";
		SetConsoleTextAttribute(color, 0x04);
		printf("                           _._       _,._\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "2. Play hard mode" << "                                     ";
		SetConsoleTextAttribute(color, 0x04);
		printf("                        _.'   `. ' .'   _`.\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "3. Play fun mode" << "                                      ";
		SetConsoleTextAttribute(color, 0x04);
		printf("              _.--\"\"`-..\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "4. Play hidden mode" << "                                   ";
		SetConsoleTextAttribute(color, 0x04);
		printf("            ,'          `.\n");
		SetConsoleTextAttribute(color, 0x70);
		cout << ">> 5. Show All Player Score <<";
		SetConsoleTextAttribute(color, 0x07);
		cout << "                        ";
		SetConsoleTextAttribute(color, 0x04);
		printf("          ,'          __  `.\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "6. Exit Game" << "                                          ";
		SetConsoleTextAttribute(color, 0x04);
		printf("         /|          \" __   \\\n");
		cout << "                                                      ";
		printf("        , |           / |.   .\n");
		cout << "                                                      ";
		printf("        |,'          !_.'|   |\n");
		cout << "                                                      ";
		printf("      ,'             '   |   |\n");
		cout << "                                                      ";
		printf("     /              |`--'|   |\n");
		cout << "                                                      ";
		printf("    |                `---'   |\n");
		cout << "                                                      ";
		printf("     .   ,                   |                       ,\".\n");
		cout << "                                                      ";
		printf("      ._     '           _'  |                    , ' \\ `\n");
		cout << "                                                      ";
		printf("  `.. `.`-...___,...---\"\"    |       __,.        ,`\"   L,|\n");
		cout << "                                                      ";
		printf("  |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \\\n");
		cout << "                                                      ";
		printf("-:..     `. `-..--_.,.<       `\"      / `.        `-/ |   .\n");
		cout << "                                                      ";
		printf("  `,         \"\"\"\"'     `.              ,'         |   |  ',,\n");
		cout << "                                                      ";
		printf("    `.      '            '            /          '    |'. |/\n");
		cout << "                                                      ";
		printf("      `.   |              \\       _,-'           |       ''\n");
		cout << "                                                      ";
		printf("        `._'               \\   '\"\\                .      |\n");
		cout << "                                                      ";
		printf("           |                '     \\                `._  ,'\n");
		cout << "                                                      ";
		printf("           |                 '     \\                 .'|\n");
		cout << "                                                      ";
		printf("           |                 .      \\                | |\n");
		cout << "                                                      ";
		printf("           |                 |       L              ,' |\n");
		cout << "                                                      ";
		printf("           `                 |       |             /   '\n");
		cout << "                                                      ";
		printf("            \\                |       |           ,'   /\n");
		cout << "                                                      ";
		printf("          ,' \\               |  _.._ ,-..___,..-'    ,'\n");
		cout << "                                                      ";
		printf("         /     .             .      `!             ,j'\n");
		cout << "                                                      ";
		printf("        /       `.          /        .           .'/\n");
		cout << "                                                      ";
		printf("       .          `.       /         |        _.'.'\n");
		cout << "                                                      ";
		printf("        `.          7`'---'          |------\"'_.'\n");
		cout << "                                                      ";
		printf("       _,.`,_     _'                ,''-----\"'\n");
		cout << "                                                      ";
		printf("   _,-_    '       `.     .'      ,\\\n");
		cout << "                                                      ";
		printf("   -\" /`.         _,'     | _  _  _.|\n");
		cout << "                                                      ";
		printf("    \"\"--'---\"\"\"\"\"'        `' '! |! /\n");
		cout << "                                                      ";
		printf("                            `\" \" -' mh\n");

		break;
	}

	case 6:
	{
		SetConsoleTextAttribute(color, 0x07);
		cout << "1. Play normal mode" << "                                   ";
		SetConsoleTextAttribute(color, 0x04);
		printf("                 .\"-,.__\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "2. Play hard mode" << "                                     ";
		SetConsoleTextAttribute(color, 0x04);
		printf("                 `.     `.  ,\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "3. Play fun mode" << "                                      ";
		SetConsoleTextAttribute(color, 0x04);
		printf("              .--'  .._,'\"-' `.\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "4. Play hidden mode" << "                                   ";
		SetConsoleTextAttribute(color, 0x04);
		printf("             .    .'         `'\n");
		SetConsoleTextAttribute(color, 0x07);
		cout << "5. Show All Player Score" << "                              ";
		SetConsoleTextAttribute(color, 0x04);
		printf("             `.   /          ,'\n");
		SetConsoleTextAttribute(color, 0x70);
		cout << ">> 6. Exit Game <<";
		SetConsoleTextAttribute(color, 0x07);
		cout << "                                    ";
		SetConsoleTextAttribute(color, 0x04);
		printf("               `  '--.   ,-\"'\n");
		cout << "                                                      ";
		printf("                `\"`   |  \\\n");
		cout << "                                                      ";
		printf("                   -. \\, |\n");
		cout << "                                                      ";
		printf("                    `--Y.'      ___.\n");
		cout << "                                                      ";
		printf("                         \\     L._, \\\n");
		cout << "                                                      ";
		printf("               _.,        `.   <  <\\                _\n");
		cout << "                                                      ";
		printf("             ,' '           `, `.   | \\            ( `\n");
		cout << "                                                      ";
		printf("          ../, `.            `  |    .\\`.           \\ \\_\n");
		cout << "                                                      ";
		printf("         ,' ,..  .           _.,'    ||\\l            )  '\".\n");
		cout << "                                                      ";
		printf("        , ,'   \\           ,'.-.`-._,'  |           .  _._`.\n");
		cout << "                                                      ";
		printf("      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\\n");
		cout << "                                                      ";
		printf("    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.\n");
		cout << "                                                      ";
		printf("    |  '          ..         `-...-\"  |  `-'      / /        . `.\n");
		cout << "                                                      ";
		printf("    | /           |L__           |    |          / /          `. `.\n");
		cout << "                                                      ";
		printf("   , /            .   .          |    |         / /             ` `\n");
		cout << "                                                      ";
		printf("  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\\n");
		cout << "                                                      ";
		printf(" / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.\n");
		cout << "                                                      ";
		printf(".  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\\n");
		cout << "                                                      ";
		printf("' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`\n");
		cout << "                                                      ";
		printf("|'      _.-\"\"` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \\\n");
		cout << "                                                      ";
		printf("||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|\n");
		cout << "                                                      ";
		printf("||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||\n");
		cout << "                                                      ";
		printf("|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||\n");
		cout << "                                                      ";
		printf("||/            _,-------7 '              . |  `-'    l         /    `||\n");
		cout << "                                                      ";
		printf(". |          ,' .-   ,' ||               | .-.        `.      .'     ||\n");
		cout << "                                                      ";
		printf(" `'        ,'    `\".'    |               |    `.        '. -.'       `'\n");
		cout << "                                                      ";
		printf("          /      ,'      |               |,'    \\-.._,.'/'\n");
		cout << "                                                      ";
		printf("          .     /        .               .       \\    .''\n");
		cout << "                                                      ";
		printf("        .`.    |         `.             /         :_,'.'\n");
		cout << "                                                      ";
		printf("          \\ `...\\   _     ,'-.        .'         /_.-'\n");
		cout << "                                                      ";
		printf("           `-.__ `,  `'   .  _.>----''.  _  __  /\n");
		cout << "                                                      ";
		printf("                .'        /\"'          |  \"'   '_\n");
		cout << "                                                      ";
		printf("               /_|.-'\\ ,\".             '.'`__'-( \\\n");
		cout << "                                                      ";
		printf("                 / ,\"'\"\\,'               `/  `-.|\" mh\n");

		break;
	}
	}
}