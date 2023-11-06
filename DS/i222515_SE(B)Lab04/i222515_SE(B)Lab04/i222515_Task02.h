#pragma once
using namespace std;

int** getArray(char** str,int size)
{
	int** arr = new int*[2];
	for (int i = 0; i < 2; i++)
	{
		arr[i] = new int[3];
	}
	
	for (int i = 0; i < size; i++)
	{
		

		for (int j = 0; j < size; j++)
		{
			
			if (str[i][j] == 'C' || str[i][j] == 'c' && i == 0)
			{
				arr[i][i] = i;
				arr[i+1][i] = j;

			}
			else if (str[i][j] == 'A' || str[i][j] == 'a' && i == 1)
			{
				arr[i-1][i] = i;
				arr[i][i] = j;

			}
			else if (str[i][j] == 'T' || str[i][j] == 't' && i == 2)
			{
				arr[i-2][i] = i;
				arr[i-1][i] = j;

			}
		}
		

	}
	return arr;
}