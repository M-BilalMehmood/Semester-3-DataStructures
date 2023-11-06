#pragma once
using namespace std;

int** insertion_sort(int** arr, int rows, int cols)
{
	int size=cols;
	for (int i = 0; i < cols; i++)
	{
		if (arr[0][i] == 999999)
		{
			size = i;
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		int temp = arr[0][i];
		int j = i - 1;
		while (j >= 0 && arr[0][j] > temp)
		{
			arr[0][j + 1] = arr[0][j];
			j--;
		}
		arr[0][j + 1] = temp;
	}	



	return arr;
}
int** selection_sort(int** arr, int rows, int cols)
{
	int size = cols;
	for (int i = 0; i < cols; i++)
	{
		if (arr[1][i] == 999999)
		{
			size = i;
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		int min = arr[1][i];
		int index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[1][j] < min)
			{
				min = arr[1][j];
				index = j;
			}
		}
		int temp = arr[1][i];
		arr[1][i] = min;
		arr[1][index] = temp;
	}	
	


	return arr;
}
int** bubble_sort(int** arr, int rows, int cols)
{
	int size = cols;
	for (int i = 0; i < cols; i++)
	{
		if (arr[2][i] == 999999)
		{
			size = i;
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[2][j] > arr[2][j + 1])
			{
				int temp = arr[2][j];
				arr[2][j] = arr[2][j + 1];
				arr[2][j + 1] = temp;
			}
		}
	}
	


	return arr;
}