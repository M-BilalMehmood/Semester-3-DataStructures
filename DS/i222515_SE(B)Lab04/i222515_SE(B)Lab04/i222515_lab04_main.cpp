#include<iostream>
#include<string>
#include<windows.h>
#include"i222515_Task01.h"
#include"i222515_Task02.h"
#include"i222515_Task03.h"
using namespace std;
int main()
{
	//----------------------Task 01----------------------

	int row = 3, col;
	cout << "Enter the max number of columns of the matrix: ";
	cin >> col;
	int** arr3 = new int* [row];
	for (int i = 0; i < row; i++)
	{
		arr3[i] = new int[col];
	}
	cout << "Enter the values of the each row and enter 999999 when done " << endl;
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		while (j < col)
		{
			cout << "Enter the value for row " << i + 1 << " and column " << j + 1 << ": ";
			cin >> arr3[i][j];
			if (arr3[i][j] == 999999)
			{
				break;
			}
			j++;
		}
	}

	system("cls");
	arr3 = insertion_sort(arr3, row, col);
	cout << "The matrix with first row sorted with insertion sort is: " << endl;
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		while (j < col)
		{
			if (arr3[i][j] == 999999)
			{
				break;
			}
			cout << arr3[i][j] << " ";
			j++;
		}
		cout << endl;
	}
	cout << endl << endl;
	arr3 = selection_sort(arr3, row, col);
	cout << "The matrix with second row sorted with selection sort is: " << endl;
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		while (j < col)
		{
			if (arr3[i][j] == 999999)
			{
				break;
			}
			cout << arr3[i][j] << " ";
			j++;
		}
		cout << endl;
	}
	cout << endl << endl;
	arr3 = bubble_sort(arr3, row, col);
	cout << "The matrix with third row sorted with bubble sort is: " << endl;
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		while (j < col)
		{
			if (arr3[i][j] == 999999)
			{
				break;
			}
			cout << arr3[i][j] << " ";
			j++;
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "The sorted matrix is: " << endl;
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		while (j < col)
		{
			if (arr3[i][j] == 999999)
			{
				break;
			}
			cout << arr3[i][j] << " ";
			j++;
		}
		cout << endl;
	}

	//----------------------Task 02----------------------
	cout << "Press any key to continue to task 02" << endl;
	system("pause");
	system("cls");
	int size=3;
	char** str = new char*[size];
	for (int i = 0; i < size; i++)
	{
		str[i] = new char[size];
	}
	
	for (int i = 0; i < size; i++)
	{
		bool check = true;
		
			for (int j = 0; j < size; j++)
			{
				cout<< "Enter the character for row " << i + 1 << " and column " << j + 1 << endl;
				cin >> str[i][j];
				if (str[i][j] == 'C' || str[i][j] == 'c' && i==0)
				{
					check = false;
					
				}
				else if (str[i][j] == 'A' || str[i][j] == 'a' && i == 1)
				{
					check = false;

				}
				else if (str[i][j] == 'T' || str[i][j] == 't' && i == 2)
				{
					check = false;

				}
			}
			if (check == true)
			{
				cout << "Invalid Input. The requred character for this row is missing.Kindly re enter the row" << endl;
				i--;
			}
		
	}

	int** arr = getArray(str, size);
	cout << "The coordinates of  CAT are: " << endl;
	for (int i = 0; i < 2; i++)
	{
		
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	
	Sleep(2000);
	system("cls");
	for (int i = 0; i < size; i++)
	{
		delete[] str[i];
	}
	delete[] str;
	for (int i = 0; i < 2; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	//----------------------Task 03----------------------
	cout << "Press any key to continue to task 03" << endl;
	system("pause");
	system("cls");
	int rows, columns;
	cout<< "Enter the rows of the matrix: ";
	cin >> rows;
	cout << "Enter the columns of the matrix: ";
	cin >> columns;

	double** arr2 = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		arr2[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "enter the value for row " << i + 1 << " and column " << j + 1 << ":";
			cin >> arr2[i][j];
			if (arr2[i][j] < 0 || arr2[i][j]>1)
			{
				cout << "Invalid Input. Kindly re enter the value" << endl;
				j--;
			}
		}

	}
	if (check_markov(arr2,rows,columns))
	{
		cout<<"It is a markov matrix"<<endl;
	}
	else
	{
		cout << "It is not a markov matrix" << endl;
	}
	for (int i = 0; i < columns; i++)
	{
		delete[] arr2[i];
	}
	delete[] arr2;


	return 0;
	

}