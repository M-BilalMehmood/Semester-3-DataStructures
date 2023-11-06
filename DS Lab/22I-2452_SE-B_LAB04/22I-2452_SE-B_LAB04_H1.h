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
	}
	//getters & setters
	void setRow(int r) { row = r; }
	void setCol(int c) { col = c; }
	void setSortin(int** arr)
};