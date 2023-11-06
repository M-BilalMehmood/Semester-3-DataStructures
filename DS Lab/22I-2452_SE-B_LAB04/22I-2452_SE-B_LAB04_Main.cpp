#include<iostream>
#include<string>
#include"22I-2452_SE-B_LAB04_H1.h"
using namespace std;

int main()
{
	cout << "\033[1;34mWelcome to Lab task 4\033[0m\n\033[1;36mChoose the problem to run (1, 2, 3)\n=> \033[0m";
	int n; cin >> n;
	if (n > 3 || n < 1)
	{
		cout << "\033[1;31mTry Again\033[0m" << endl;
		main();
	}
	system("cls");
	switch (n)
	{
		case 1:
		{
			cout << "\033[1;35mTASK 01\nEnter the number of rows \033[0m \033[1;31m(Only Enter 3 or program will run again)\033[0m\033[1;35m: \033[0m";
			int row; cin >> row;
			if (row != 3)
			{
				system("cls");
				main();
			}
			int col1, col2, col3;
			int** sortin = new int* [row];
			for (int i = 0; i < row; i++)
			{
				cout << "\033[1;35mEnter the number of columns (Row \033[0m" << i + 1 << "\033[1;35m): \033[0m";
				if (i == 0) { cin >> col1; sortin[i] = new int[col1]; }
				if (i == 1) { cin >> col2; sortin[i] = new int[col2]; }
				if (i == 2) { cin >> col3; sortin[i] = new int[col3]; }
			}
			cout << "Enter Matrix" << endl;
			for (int i = 0; i < row; i++)
			{
				if (i == 0) 
				{
					for (int j = 0; j < col1; j++)
					{
						cout << "(" << i + 1 << ", " << j + 1 << "): ";
						cin >> sortin[i][j];
					}
				}
				if (i == 1)
				{
					for (int j = 0; j < col2; j++)
					{
						cout << "(" << i + 1 << ", " << j + 1 << "): ";
						cin >> sortin[i][j];
					}
				}
				if (i == 2)
				{
					for (int j = 0; j < col3; j++)
					{
						cout << "(" << i + 1 << ", " << j + 1 << "): ";
						cin >> sortin[i][j];
					}
				}
			}
			sort n;
			//sort(col1, col2, col3, sortin[][]);
		}
		case 3:
		{
			cout << "\033[1;35mTASK 03\nEnter the number of rows: \033[0m";
			int row; cin >> row;
			cout << "\033[1;35mEnter the number of columns: \033[0m";
			int col; cin >> col;
			if (checkMarkov(row, col) == true)
			{
				cout << "\033[1;32mThe entered matrix is Markov\033[0m" << endl;
			}
			else
			{
				cout << "\033[1;31mThe entered matrix is not Markov\033[0m" << endl;
			}
			break;
		}
		default:
		{
			//Not required
			break;
		}
	}
}