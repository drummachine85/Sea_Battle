// Sea_Battle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
#include<istream>

#include<stdio.h>
#include<fcntl.h>
#include<io.h>

using namespace std;
const int ROW = 12;
const int COLMN = 12;

void print_arry(int arry[12][12]);
void init_mas(int arry[12][12]);
void user(char user_name[80]);
void insert(int arry[12][12],int choise);

int charTostring(char cordinates ); // bukvi koordinat v vozvraschaemij int

bool check(int arry[12][12], int a, int b);

int ship_choise();// nuzhno peredelatj--->sdelatj vozvraschatj 2 int znachenija
int main()
{
	//_setmode(_fileno(stdout),_O_U16TEXT);

	char user_name[80];
	int battle_mass[ROW][COLMN];
	int ship_coordinates[4][4];
	user(user_name);
	init_mas(battle_mass);
	int choise=ship_choise();
	insert(battle_mass,choise);
	print_arry(battle_mass);

	return 0;
}
void init_mas(int arry[12][12])
{
	for (int i = 1;i < 11;i++)
	{

		for (int j = 0;j < 11; j++) {

			if (j == 0)
			{
				arry[i][j] = i;
			}
			else
			{
				int c = 0;
				arry[i][j] = { c };
			}
		}

	}
	char c = 'A';
	for (int q = 0;q < 1;q++)
	{
		for (int j = 0;j < 11; j++)
		{
			if (j == 0)
			{
				arry[q][j] = '*';
				j++;
			}
			arry[q][j] = { c };
			c++;
		}
	}
}
void print_arry(int arry[12][12])
{
	for (int i = 0;i < 11;i++)
	{
		for (int j = 0;j < 11; j++)
		{
			if (arry[i][j] >= 11)
			{
				printf("%c", arry[i][j]);
			}
			else
			{
				cout << arry[i][j];
			}
		}
		cout << endl;
	}
}
void user(char user_name[80])
{
	user_name[80];
	cout << '\t' << "Welcome user" << endl;
	cout << '\t' << "Please inter your name" << endl;
	cin >> user_name;
	cout << '\n' << "Your name : " << user_name << endl;
}
void insert(int arry[12][12],int choise)   //Insert ship coordinates
{
	char a;
	int row;
	int colmn;
	bool y_n=true;
	bool endOfinsert=true;
	
	do
	{
		cout << "Vvedite coordinati" << endl;

		cout << "Po vertikali ot 1 do 10: ";
		cin >> colmn;

		cout << "Po gorizontali ot A do J: ";
		cin >> a;
		row = charTostring(a);


		bool check_arry = check(arry, colmn, row);
		if (check_arry == true)// vozvraschaet bool -- esli true zapisj v massiv 'x'
		{
			arry[colmn][row] = 'x';
			y_n = false;
			choise--;
		}
		if (check_arry == false)
		{
			cout << '\t' << "Pole uzhe zapolneno!" << '\n';
			cout << '\t' << "Vvedite drugie koordinati!" << '\n';
		}
		if (choise == 0) { endOfinsert = false; }
	} while (y_n||endOfinsert);
}

int ship_choise()
{
	cout << "Viberite korablj"<<endl;
	int choise;
	cout << "Nazhmite (1) chtobivibratj odinochnij [1] korablj " << endl;
	cout << "Nazhmite (2) chtobivibratj dvojnoj  [1][2] korablj " << endl;
	cout << "Nazhmite (3) chtobivibratj trojnoj [1][2][3] korablj " << endl;
	cout << "Nazhmite (4) chtobivibratj  [1][2][3][4] korablj " << endl;
	bool trueNumber=true;
	do {
		cin >> choise;
		if (choise <= 0) { cout << "Vi vveli nevenoe chislo."<<endl;}
		if (choise > 4) {cout << "Vi vveli nevernoe chislo" << endl;}
		else { trueNumber =false ; }
	} while (trueNumber);

	switch (choise)
	{
	case 1:
		cout << "You choise is single section ship [1]" << endl;
		return choise;
		break;
	case 2:
		cout << "You choise is two-piece section ship [1][2]" << endl;
		return choise;
		break;
	case 3:
		cout << "You choise three-section ship [1][2][3]" << endl;
		return choise;
		break;

	case 4:cout << "You choise is single four-section ship [1][2][3][4]" << endl;
		return choise;
		break;

	default:cout << "Vi vveli ne praveljnij nomer" << endl;
	}
	return 0;

}

bool check(int arry[12][12], int a, int b)
{
	/*for (int j = 0;j < 11;j++)
	{
		for (int i=0;i<11;i++)
		{
			if (arry[j][i] == 120)
			{
				return false;
			}
		}
	}*/
	if (arry[a][b] == 120)
	{
		return false;
	}
	cout << "Eto test funkcii" << '\n';
	return true;
}
int charTostring(char cordinates)
{
	switch (cordinates)
	{
	case 'A':
		return 1;
		break;
	case 'B':
		return 2;
		break;
	case 'C':
		return 3;
		break;
	case 'D':
		return 4;
		break;
	case 'E':
		return 5;
		break;
	case 'F':
		return 6;
		break;
	case'G':
		return 7;
		break;
	case 'H':
		return 8;
		break;
	case 'I':
		return 9;
		break;
	case 'J':
		return 10;
		break;
	default: cout << "Vvedite zaglavnuju bukvu!";
}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
