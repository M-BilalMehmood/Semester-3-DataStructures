#pragma once
#include<iostream>
#include<string>
using namespace std;

bool checkMarkov(int row, int col)
{
	float **markov = new float*[row];
    for (int i = 0; i < row; i++) 
    {
        markov[i] = new float[col];
    }
    cout << "Enter Matrix" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "(" << i + 1 << ", " << j + 1 << "): ";
            cin >> markov[i][j];
        }
    }

    bool flag = false;
    float check;
    for (int i = 0; i < row; i++)
    {
        check = 0;
        for (int j = 0; j < col; j++)
        {
            check = check + markov[i][j];
        }
        if (check == 1)
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}