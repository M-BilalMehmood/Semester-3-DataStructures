#pragma once
#include<iostream>
#include<string>
#include"22I-2452_SE-B_LAB04_H2.h"
#include"22I-2452_SE-B_LAB04_H3.h"
using namespace std;

class sort
{
private:
	int row;
	int col;
	int** sortin;
public:
	sort()
	{
		sortin = nullptr;
		row = 0;
		col = 0;
	}
	sort(int row, int col, int** arr)
	{
		int** sortin = new int* [row];
		for (int i = 0; i < row; i++)
		{
			sortin[i] = new int[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				sortin[i][j] = arr[i][j];
			}
		}
		for (int i = 1; i < col; i++) //insertion sort on column 1
		{
			int key = sortin[0][i];
			int j = i - 1;
			while (j >= 0 && sortin[0][j] > key)
			{
				sortin[0][j + 1] = sortin[0][j];
				j--;
			}
			sortin[0][j + 1] = key;
		}

		for (int i = 0; i < col; i++) //selection sort on column 2
		{
			int min = sortin[1][i];
			int minimum = i;
			for (int j = i + 1; j < col; j++)
			{
				if (sortin[1][j] < min)
				{
					min = sortin[1][j];
					minimum = j;
				}
			}
			int temp = sortin[1][i];
			sortin[1][i] = sortin[1][minimum];
			sortin[1][minimum] = temp;
		}

		for (int i = 0; i < col - 1; i++) //bubble sort on column 3
		{
			for (int j = 0; j < col - i - 1; j++)
			{
				if (sortin[2][j] > sortin[2][j + 1])
				{
					int temp = sortin[2][j];
					sortin[2][j] = sortin[2][j + 1];
					sortin[2][j + 1] = temp;
				}
			}
		}
		cout << "\033[1;32mSorted Matrix\033[0m" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << sortin[i][j] << " ";
			}
			cout << endl;
		}
	}
	//getters & setters
	void setRow(int r) { row = r; }
	void setCol(int c) { col = c; }
};