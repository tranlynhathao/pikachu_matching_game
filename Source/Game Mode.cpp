#include "Game Mode.h"

// Game mode
void EasyGame()
{
	srand(time(0)); // to random
	system("cls"); // clear screen
	char name[100];
	cout << "Enter name: "; // enter name store to name[100]
	cin.getline(name, 100);
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
	int start = clock(); // start time
	char** a = new char* [10];// init 2D array
	for (int i = 0; i < 10; i++)
	{
		a[i] = new char[10];
	}
	gen2D(a); // create random arr
	int x = 1, y = 1, x1 = -1, y1 = -1, x2 = -1, y2 = -1; // first position when start game
	char getCommand = 0; // get keyboard is pressed
	int countTimes = 0; // count time press enter (choose 2 to check)
	Node* pHead = new Node; // linked list to Redo
	pHead = nullptr;
	bool checkMove = false; // if move suggestion run, not draw new board
	while (!checkEmpty(a)) // check if empty -> end game
	{
		while (!checkValidPairs(a)) // if not pair are available, random another array
		{
			randomArr(a);
		}
		system("cls"); // clear sreen to draw board
		if (checkMove) // check if moveSuggestion
		{
			moveSuggestion(a, x, y);
			checkMove = false;
		}
		else
			repBoard(a, 10, 10, x, y, x1, y1, x2, y2);
		getCommand = _getch(); // get keyboard is pressed
		PlaySound(L"Music/choose.wav", NULL, SND_FILENAME | SND_ASYNC); // play sound when press
		if (getCommand == 'f') // moveSuggestion
		{
			checkMove = true;
			continue;
		}
		if (getCommand >= '1' && getCommand <= '8') // get the x address
		{
			x = int(getCommand) - '0'; // convert ascii to number
			getCommand = _getch(); // get y address
			if (getCommand >= '1' && getCommand <= '8')
			{
				y = int(getCommand) - '0';
				system("cls");
				repBoard(a, 10, 10, x, y, x1, y1, x2, y2); // move to that address
				getCommand = _getch();
				if (getCommand != 13)
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
		if (getCommand == 'h') // press 'h' call moveSuggestion function
		{
			addHead(pHead, a);
			deleteSuggestion(a);
			continue;
		}
		if (getCommand == 'v') // press v to enter giftcode
		{
			system("cls");
			char code[10];
			cout << "Enter giftcode: ";
			cin.getline(code, 10);
			if (strcmp(code, "CHUALANH") == 0)
			{
				for (int v = 0; v < 16; v++)
				{
					deleteSuggestion(a);
				}
			}
			else
				continue;
		}
		if (getCommand == 'r')
		{
			redo(pHead, a);
			removeHead(pHead); // remove the latest array
			continue;
		}
		if (getCommand == 13 && countTimes == 0 && a[x][y] != ' ') // enter first time move x1 y1 to x y address
		{
			x1 = x;
			y1 = y;
			countTimes++;
			system("cls");
			repBoard(a, 10, 10, x, y, x1, y1, x2, y2);
		}
		else if (getCommand == 13 && countTimes == 1 && a[x][y] != ' ')// if enter second times move x2 y2 to x y address
		{
			x2 = x;
			y2 = y;
			countTimes++;
			system("cls");
			repBoard(a, 10, 10, x, y, x1, y1, x2, y2);
		}
		if (countTimes == 2) // enter 2 times check x1 y2 x2 y2 if true delete
		{
			if (checkI(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC); // if true play sound 
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0; // reset enter variable
			}
			else if (checkL(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);// if true play sound 
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0; // reset enter
			}
			else if (checkZ(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);// if true play sound 
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;//reset enter
			}
			else if (checkU(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);// if true play sound 
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;//reset enter
			}
			else
			{
				PlaySound(L"Music/buzzer.wav", NULL, SND_FILENAME | SND_ASYNC);// if false play sound 
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;//reset enter
			}
		}
		if (getCommand == 'w' || getCommand == 72) // move up
		{
			if (x > 1)
			{
				x--;
			}
		}
		if (getCommand == 's' || getCommand == 80) // moce down
		{
			if (x < 8)
			{
				x++;
			}
		}
		if (getCommand == 'd' || getCommand == 77) // move right
		{
			if (y < 8)
			{
				y++;
			}
		}
		if (getCommand == 'a' || getCommand == 75)//move left
		{
			if (y > 1)
			{
				y--;
			}
		}
	}
	PlaySound(L"Music/Legend.wav", NULL, SND_FILENAME | SND_ASYNC); // when finish game play sound
	removeAll(pHead); // delete linked list
	for (int i = 0; i < 10; i++)
	{
		delete[] a[i];// deallocate
	}
	delete[]a;
	int end = clock(); // time when end
	int time = (end - start) / 1000; // time play game
	system("cls");
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 0x01);
	// print pokemon with score
	cout << "\t";
	cout << "                                  ,'\\" << endl;
	cout << "\t";
	cout << "    _.----.____, '  _\\   ___    ___     ____" << endl;
	cout << "\t";
	cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << endl;
	cout << "\t";
	cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << endl;
	cout << "\t";
	cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << endl;
	cout << "\t";
	cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << endl;
	cout << "\t";
	cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << endl;
	cout << "\t";
	SetConsoleTextAttribute(color, 0x06);
	cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << endl;
	cout << "\t";
	cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << endl;
	cout << "\t";
	cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << endl;
	cout << "\t";
	cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << endl;
	cout << "\t";
	cout << "                                `'                            '-._|" << endl;
	SetConsoleTextAttribute(color, 0x07);
	cout << "\t\tCongratulation !! You are the winner with ";
	SetConsoleTextAttribute(color, 0x30);
	cout << time << " seconds" << endl;
	SetConsoleTextAttribute(color, 0x07);
	cout << endl;
	inputAndPrintFile("Text/normal.txt", name, time); // store score and name player
	system("pause");
}
void FunGame()
{
	srand(time(0));// to random
	system("cls");// clear screen
	char name[100];
	cout << "Enter name: ";
	cin.getline(name, 100);// enter name store to name[100]
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
	int start = clock();// start time
	char** a = new char* [10];// init 2D array
	for (int i = 0; i < 10; i++)
	{
		a[i] = new char[10];
	}
	gen2D(a);// create random arr
	int x = 1, y = 1, x1 = -1, y1 = -1, x2 = -1, y2 = -1;// first position when start game
	char getCommand = 0;// get keyboard is pressed
	int countTimes = 0;// count time press enter (choose 2 to check)
	Node* pHead = new Node;// linked list to Redo
	pHead = nullptr;
	bool checkMove = false;// if move suggestion run, not draw new board
	while (!checkEmpty(a))// check if empty -> end game
	{
		while (!checkValidPairs(a))// if not pair are available, random another array and swap
		{
			randomArr(a);
			swapArr(a);
		}
		system("cls");// clear sreen to draw board
		if (checkMove)// check if moveSuggestion
		{
			moveSuggestion(a, x, y);
			checkMove = false;
		}
		else
			repBoard(a, 10, 10, x, y, x1, y1, x2, y2);
		getCommand = _getch();// get keyboard is pressed
		PlaySound(L"Music/choose.wav", NULL, SND_FILENAME | SND_ASYNC); // play sound when press
		if (getCommand >= '1' && getCommand <= '8')// get the x address
		{
			x = int(getCommand) - '0';// convert ascii to number
			getCommand = _getch(); // get y address
			if (getCommand >= '1' && getCommand <= '8')
			{
				y = int(getCommand) - '0';
				system("cls");
				repBoard(a, 10, 10, x, y, x1, y1, x2, y2);// move to that address
				getCommand = _getch();
				if (getCommand != 13)
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
		if (getCommand == 'h')// press 'h' call deleteSuggestion function
		{
			addHead(pHead, a);
			deleteSuggestion(a);
			randomArr(a);
			swapArr(a);
		}
		if (getCommand == 'v')// press v to enter giftcode
		{
			system("cls");
			char code[10];
			cout << "Enter giftcode: ";
			cin.getline(code, 10);
			if (strcmp(code, "10DIEM") == 0)
			{
				for (int v = 0; v < 16; v++)
				{
					deleteSuggestion(a);
				}
			}
			else
				continue;
		}
		if (getCommand == 'r')
		{
			redo(pHead, a);
			removeHead(pHead);// remove the latest array
			continue;
		}
		if (getCommand == 'f')// moveSuggestion
		{
			checkMove = true;
			continue;
		}
		if (getCommand == 13 && countTimes == 0 && a[x][y] != ' ')// enter first time move x1 y1 to x y address
		{
			x1 = x;
			y1 = y;
			countTimes++;
			system("cls");
			repBoard(a, 10, 10, x, y, x1, y1, x2, y2);
		}
		else if (getCommand == 13 && countTimes == 1 && a[x][y] != ' ')// if enter second times move x2 y2 to x y address
		{
			x2 = x;
			y2 = y;
			countTimes++;
			system("cls");
			repBoard(a, 10, 10, x, y, x1, y1, x2, y2);
		}
		if (countTimes == 2)// enter 2 times check x1 y2 x2 y2 if true delete
		{
			if (checkI(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);// if true play sound 
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;// reset enter variable
				randomArr(a);
				swapArr(a);
				continue;
			}
			else if (checkL(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);// if true play sound 
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;// reset enter
				randomArr(a);
				swapArr(a);
				continue;
			}
			else if (checkZ(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC); // play sound
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;// reset enter
				randomArr(a);
				swapArr(a);
				continue;
			}
			else if (checkU(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;
				randomArr(a);
				swapArr(a);
				continue;
			}
			else
			{
				PlaySound(L"Music/buzzer.wav", NULL, SND_FILENAME | SND_ASYNC);
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;
				randomArr(a);
				swapArr(a);
				continue;
			}
		}
		if (getCommand == 'w' || getCommand == 72)
		{
			if (x > 1)
			{
				x--;
			}
		}
		if (getCommand == 's' || getCommand == 80)
		{
			if (x < 8)
			{
				x++;
			}
		}
		if (getCommand == 'd' || getCommand == 77)
		{
			if (y < 8)
			{
				y++;
			}
		}
		if (getCommand == 'a' || getCommand == 75)
		{
			if (y > 1)
			{
				y--;
			}
		}
	}
	PlaySound(L"Music/Legend.wav", NULL, SND_FILENAME | SND_ASYNC);// when finish game play sound
	removeAll(pHead);// delete linked list
	for (int i = 0; i < 10; i++)
	{
		delete[] a[i];// deallocate
	}
	delete[]a;
	int end = clock();
	int time = (end - start) / 1000;// time play when end
	system("cls");
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 0x01);
	// print pokemon with score
	cout << "\t";
	cout << "                                  ,'\\" << endl;
	cout << "\t";
	cout << "    _.----.____, '  _\\   ___    ___     ____" << endl;
	cout << "\t";
	cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << endl;
	cout << "\t";
	cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << endl;
	cout << "\t";
	cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << endl;
	cout << "\t";
	cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << endl;
	cout << "\t";
	cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << endl;
	cout << "\t";
	SetConsoleTextAttribute(color, 0x06);
	cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << endl;
	cout << "\t";
	cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << endl;
	cout << "\t";
	cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << endl;
	cout << "\t";
	cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << endl;
	cout << "\t";
	cout << "                                `'                            '-._|" << endl;
	SetConsoleTextAttribute(color, 0x07);
	cout << "\t\tCongratulation !! You are the winner with ";
	SetConsoleTextAttribute(color, 0x30);
	cout << time << " seconds" << endl;
	SetConsoleTextAttribute(color, 0x07);
	cout << endl;
	inputAndPrintFile("Text/fungame.txt", name, time);// store score and name player
	system("pause");
}
void HardGame()
{
	// comment same with Easy game and fun game
	srand(time(0));
	system("cls");
	char name[100];
	cout << "Enter name: ";
	cin.getline(name, 100);
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
	int start = clock();
	int score = 0;
	char** a = new char* [10];// init 2D array
	for (int i = 0; i < 10; i++)
	{
		a[i] = new char[10];
	}
	gen2D(a);
	int x = 1, y = 1, x1 = -1, y1 = -1, x2 = -1, y2 = -1;
	char getCommand = 0;
	int countTimes = 0;
	Node* pHead = new Node;
	pHead = nullptr;
	bool checkMove = false;
	while (!checkEmpty(a))
	{
		while (!checkValidPairs(a))
		{
			randomArr(a);
			swapArr(a);
		}
		system("cls");
		if (checkMove)
		{
			moveSuggestion(a, x, y);
			checkMove = false;
		}
		else
			repBoard(a, 10, 10, x, y, x1, y1, x2, y2);
		getCommand = _getch();
		PlaySound(L"Music/choose.wav", NULL, SND_FILENAME | SND_ASYNC);
		if (getCommand == 'f')
		{
			checkMove = true;
			continue;
		}
		if (getCommand >= '1' && getCommand <= '8')
		{
			x = int(getCommand) - '0';
			getCommand = _getch();
			if (getCommand >= '1' && getCommand <= '8')
			{
				y = int(getCommand) - '0';
				system("cls");
				repBoard(a, 10, 10, x, y, x1, y1, x2, y2);
				getCommand = _getch();
				if (getCommand != 13)
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
		if (getCommand == 'h')
		{
			addHead(pHead, a);
			deleteSuggestion(a);
			for (int i = 1; i < 9; i++)
			{
				int count = 0;
				for (int k = 1; k < 9 - count; k++)
				{
					while (a[i][k] == ' ' && k < 9 - count)
					{
						count++;
						swap(a[i][k], a[i][9 - count]);
					}
				}

			}
			int count = 0;
			for (int i = 1; i < 9 - count; i++)
			{
				bool check = true;
				while (check && i < 9 - count)
				{
					for (int k = 1; k < 9; k++)
					{
						if (a[i][k] != ' ')
						{
							check = false;
							break;
						}
					}
					if (check)
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
			continue;
		}
		if (getCommand == 'v')
		{
			system("cls");
			char code[10];
			cout << "Enter giftcode: ";
			cin.getline(code, 10);
			if (strcmp(code, "DUNGNHAPCODENUA") == 0)
			{
				for (int v = 0; v < 32; v++)
				{
					deleteSuggestion(a);
				}
			}
			else
				continue;
		}
		if (getCommand == 'r')
		{
			redo(pHead, a);
			removeHead(pHead);
			continue;
		}
		if (getCommand == 13 && countTimes == 0 && a[x][y] != ' ')
		{
			x1 = x;
			y1 = y;
			countTimes++;
			system("cls");
			repBoard(a, 10, 10, x, y, x1, y1, x2, y2);
		}
		else if (getCommand == 13 && countTimes == 1 && a[x][y] != ' ')
		{
			x2 = x;
			y2 = y;
			countTimes++;
			system("cls");
			repBoard(a, 10, 10, x, y, x1, y1, x2, y2);
		}
		if (countTimes == 2)
		{
			if (checkI(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;
				swapArr(a);
				continue;
			}
			else if (checkL(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;
				swapArr(a);
				continue;
			}
			else if (checkZ(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;
				swapArr(a);
				continue;
			}
			else if (checkU(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;
				swapArr(a);
				continue;
			}
			else
			{
				PlaySound(L"Music/buzzer.wav", NULL, SND_FILENAME | SND_ASYNC);
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;
				// false all back to first array
				while (pHead)
				{
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							a[i][j] = pHead->b[i][j];
						}
					}
					removeHead(pHead);
				}
				continue;
			}
		}
		if (getCommand == 'w' || getCommand == 72)
		{
			if (x > 1)
			{
				x--;
			}
		}
		if (getCommand == 's' || getCommand == 80)
		{
			if (x < 8)
			{
				x++;
			}
		}
		if (getCommand == 'd' || getCommand == 77)
		{
			if (y < 8)
			{
				y++;
			}
		}
		if (getCommand == 'a' || getCommand == 75)
		{
			if (y > 1)
			{
				y--;
			}
		}
	}
	PlaySound(L"Music/Legend.wav", NULL, SND_FILENAME | SND_ASYNC);
	removeAll(pHead);
	for (int i = 0; i < 10; i++)
	{
		delete[] a[i]; // deallocate
	}
	delete[]a;
	int end = clock();
	int time = (end - start) / 1000;
	system("cls");
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 0x01);
	// print pokemon with score
	cout << "\t";
	cout << "                                  ,'\\" << endl;
	cout << "\t";
	cout << "    _.----.____, '  _\\   ___    ___     ____" << endl;
	cout << "\t";
	cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << endl;
	cout << "\t";
	cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << endl;
	cout << "\t";
	cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << endl;
	cout << "\t";
	cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << endl;
	cout << "\t";
	cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << endl;
	cout << "\t";
	SetConsoleTextAttribute(color, 0x06);
	cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << endl;
	cout << "\t";
	cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << endl;
	cout << "\t";
	cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << endl;
	cout << "\t";
	cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << endl;
	cout << "\t";
	cout << "                                `'                            '-._|" << endl;
	SetConsoleTextAttribute(color, 0x07);
	cout << "\t\tCongratulation !! You are the winner with ";
	SetConsoleTextAttribute(color, 0x30);
	cout << time << " seconds" << endl;
	SetConsoleTextAttribute(color, 0x07);
	cout << endl;
	inputAndPrintFile("Text/Hard.txt", name, time);
	system("pause");
}
void HiddenGame()
{
	srand(time(0)); // to random
	system("cls"); // clear screen
	char name[100];
	cout << "Enter name: "; // enter name store to name[100]
	cin.getline(name, 100);
	PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
	int start = clock(); // start time
	char** a = new char* [10];// init 2D array
	for (int i = 0; i < 10; i++)
	{
		a[i] = new char[10];
	}
	gen2D(a); // create random arr
	int x = 1, y = 1, x1 = -1, y1 = -1, x2 = -1, y2 = -1; // first position when start game
	char getCommand = 0; // get keyboard is pressed
	int countTimes = 0; // count time press enter (choose 2 to check)
	Node* pHead = new Node; // linked list to Redo
	pHead = nullptr;
	bool checkMove = false; // if move suggestion run, not draw new board
	while (!checkEmpty(a)) // check if empty -> end game
	{
		while (!checkValidPairs(a)) // if not pair are available, random another array
		{
			randomArr(a);
		}
		system("cls"); // clear sreen to draw board
		if (checkMove) // check if moveSuggestion
		{
			moveSuggestionHidden(a, x, y);
			checkMove = false;
		}
		else
			repBoardHidden(a, 10, 10, x, y, x1, y1, x2, y2);
		getCommand = _getch(); // get keyboard is pressed
		PlaySound(L"Music/choose.wav", NULL, SND_FILENAME | SND_ASYNC); // play sound when press
		if (getCommand == 'f') // moveSuggestion
		{
			checkMove = true;
			continue;
		}
		if (getCommand >= '1' && getCommand <= '8') // get the x address
		{
			x = int(getCommand) - '0'; // convert ascii to number
			getCommand = _getch(); // get y address
			if (getCommand >= '1' && getCommand <= '8')
			{
				y = int(getCommand) - '0';
				system("cls");
				repBoardHidden(a, 10, 10, x, y, x1, y1, x2, y2); // move to that address
				getCommand = _getch();
				if (getCommand != 13)
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
		if (getCommand == 'h') // press 'h' call moveSuggestion function
		{
			addHead(pHead, a);
			deleteSuggestion(a);
			continue;
		}
		if (getCommand == 'v') // press v to enter giftcode
		{
			system("cls");
			char code[10];
			cout << "Enter giftcode: ";
			cin.getline(code, 10);
			if (strcmp(code, "HAY_CHOI_DE_TRAI_NGHIEM") == 0)
			{
				for (int v = 0; v < 16; v++)
				{
					deleteSuggestion(a);
				}
			}
			else
				continue;
		}
		if (getCommand == 'r')
		{
			redo(pHead, a);
			removeHead(pHead); // remove the latest array
			continue;
		}
		if (getCommand == 13 && countTimes == 0 && a[x][y] != ' ') // enter first time move x1 y1 to x y address
		{
			x1 = x;
			y1 = y;
			countTimes++;
			system("cls");
			repBoardHidden(a, 10, 10, x, y, x1, y1, x2, y2);
		}
		else if (getCommand == 13 && countTimes == 1 && a[x][y] != ' ')// if enter second times move x2 y2 to x y address
		{
			x2 = x;
			y2 = y;
			countTimes++;
			system("cls");
			repBoardHidden(a, 10, 10, x, y, x1, y1, x2, y2);
		}
		if (countTimes == 2) // enter 2 times check x1 y2 x2 y2 if true delete
		{
			if (checkI(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC); // if true play sound 
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0; // reset enter variable
			}
			else if (checkL(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);// if true play sound 
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0; // reset enter
			}
			else if (checkZ(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);// if true play sound 
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;//reset enter
			}
			else if (checkU(a, x1, y1, x2, y2) && (a[x1][y1] == a[x2][y2]) && !(x1 == x2 && y1 == y2))
			{
				PlaySound(L"Music/mario.wav", NULL, SND_FILENAME | SND_ASYNC);// if true play sound 
				addHead(pHead, a);
				a[x1][y1] = ' ';
				a[x2][y2] = ' ';
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;//reset enter
			}
			else
			{
				PlaySound(L"Music/buzzer.wav", NULL, SND_FILENAME | SND_ASYNC);// if false play sound 
				x1 = -1;
				x2 = -1;
				y1 = -1;
				y2 = -1;
				countTimes = 0;//reset enter
			}
		}
		if (getCommand == 'w' || getCommand == 72) // move up
		{
			if (x > 1)
			{
				x--;
			}
		}
		if (getCommand == 's' || getCommand == 80) // moce down
		{
			if (x < 8)
			{
				x++;
			}
		}
		if (getCommand == 'd' || getCommand == 77) // move right
		{
			if (y < 8)
			{
				y++;
			}
		}
		if (getCommand == 'a' || getCommand == 75)//move left
		{
			if (y > 1)
			{
				y--;
			}
		}
	}
	PlaySound(L"Music/Legend.wav", NULL, SND_FILENAME | SND_ASYNC); // when finish game play sound
	removeAll(pHead); // delete linked list
	for (int i = 0; i < 10; i++)
	{
		delete[] a[i];// deallocate
	}
	delete[]a;
	int end = clock(); // time when end
	int time = (end - start) / 1000; // time play game
	system("cls");
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 0x01);
	// print pokemon with score
	cout << "\t";
	cout << "                                  ,'\\" << endl;
	cout << "\t";
	cout << "    _.----.____, '  _\\   ___    ___     ____" << endl;
	cout << "\t";
	cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << endl;
	cout << "\t";
	cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << endl;
	cout << "\t";
	cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << endl;
	cout << "\t";
	cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << endl;
	cout << "\t";
	cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << endl;
	cout << "\t";
	SetConsoleTextAttribute(color, 0x06);
	cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << endl;
	cout << "\t";
	cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << endl;
	cout << "\t";
	cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << endl;
	cout << "\t";
	cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << endl;
	cout << "\t";
	cout << "                                `'                            '-._|" << endl;
	SetConsoleTextAttribute(color, 0x07);
	cout << "\t\tCongratulation !! You are the winner with ";
	SetConsoleTextAttribute(color, 0x30);
	cout << time << " seconds" << endl;
	SetConsoleTextAttribute(color, 0x07);
	cout << endl;
	inputAndPrintFile("Text/hidden.txt", name, time); // store score and name player
	system("pause");
}