#pragma once
#include<iostream>
#include<cstring>
using namespace std;

char** words_to_sentence(int row, int col)
{
    char* word = new char[col];
    char** sentence = new char* [row];
    for (int i = 0; i < row; i++)
    {
        sentence[i] = new char[col];
    }

    for (int i = 0; i < row; i++)
    {
        cout << "Enter word " << i + 1 << ": ";
        cin >> word;
        int count = 0;
        for (int j = 0; j < col; j++)
        {
            sentence[i][j] = word[j];
        }
    }
    cout << "The sentence is: ";
    /*for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << sentence[i][j];
        }
    }*/
    return sentence;
}