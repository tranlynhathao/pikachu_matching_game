#include "ReadFile.h"

void readFile(string name)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 0x01);
	// read file to print ranking board
	ifstream in;
	in.open(name);
	if (!in)
	{
		cout << "Can not open file";
		return;
	}
	char temp[20];
	in.getline(temp, 20, '\n');
	int n = 0;
	if (in.eof()) // check empty
	{
		cout << "                            " << "|                             ";
		SetConsoleTextAttribute(color, 0x06);
		cout << "No one play this mode !!                          ";
		SetConsoleTextAttribute(color, 0x01);
		cout << "|" << endl;
		return;
	}
	Storage* store = new Storage[5]; // only print top 5
	while (!in.eof())
	{
		in.getline(store[n].name, 100, ' ');
		in >> store[n].score;
		in.ignore();
		n++;
	}
	for (int i = 0; i < n; i++) // 21 + 23 + strlen(name)
	{
		cout << "                            |";
		int len = 80 - (26 + 23 + strlen(store[i].name)); // count blank have to fill
		if (store[i].score < 10)
		{
			len += 1;
		}
		if (store[i].score >= 100)
		{
			len--;
		}
		cout << "                        ";
		SetConsoleTextAttribute(color, 0x06);
		cout << " Top " << i + 1 << ": " << store[i].name << " with " << store[i].score << " seconds";
		SetConsoleTextAttribute(color, 0x01);
		for (int i = 0; i < len; i++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
}
void inputAndPrintFile(string namef, char a[100], int time)
{
	//read file and then sort with seconds then print file
	Storage* store = new Storage[10]; // this struct store name and seconds
	ifstream in;
	in.open(namef);
	if (!in)
	{
		cout << "Can not open file";
		delete[] store;
		system("pause");
		return;
	}
	int n = 0;
	char temp[20];
	in.getline(temp, 20, '\n');
	while (!in.eof())
	{
		in.getline(store[n].name, 100, ' ');
		in >> store[n].score;
		in.ignore();
		n++;
	}
	in.close();
	strcpy(store[n].name, a);
	store[n].score = time;
	// sort
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = i + 1; j < n + 1; j++)
		{
			if (store[i].score > store[j].score)
			{
				swap(store[i], store[j]);
			}
		}
	}
	ofstream out;
	out.open(namef);
	if (!out)
	{
		cout << "Can not open file" << endl;
		delete[] store;
		system("pause");
		return;
	}
	out << temp << endl;
	for (int i = 0; i < n + 1; i++)
	{
		if (i == 4) // print 5 and stop if not enough 5 print all
		{
			out << store[i].name << " " << store[i].score;
			break;
		}
		if (i == n)
		{
			out << store[i].name << " " << store[i].score;
			break;
		}
		out << store[i].name << " " << store[i].score << endl;
	}
	delete[] store;
}