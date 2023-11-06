#pragma once
using namespace std;
bool check_markov(double** arr, int rows,int cols)
{
	bool check = true;
	for (int i = 0; i < rows; i++)
	{
		double sum = 0;
		for (int j = 0; j < cols; j++)
		{
			sum += arr[i][j];
		}
		if (sum != 1)
		{
			check = false;
			break;
		}
	}
	return check;
}
