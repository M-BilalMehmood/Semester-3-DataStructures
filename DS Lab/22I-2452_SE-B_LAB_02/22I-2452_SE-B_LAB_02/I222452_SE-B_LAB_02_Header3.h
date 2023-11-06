#pragma once
#include<iostream>
#include<string>
using namespace std;

template <typename T>
int comparison(T arr[], T arr2[], T arr3[], int size1, int size2)
{
    cout << "The common elements are: ";
    int counter = 0;
    bool checka = false;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr[i] == arr2[j])
            {
                cout << arr[i] << " ";
                checka = true;
            }
        }
    }
    if (checka == false)
    {
        cout << "No common elements" << endl;
    }
    cout << endl << "The concatenated array is: ";
    for (int i = 0; i < size1; i++)
    {
        bool found = false;
        for (int j = 0; j < size2; j++)
        {
            if (arr[i] == arr2[j])
            {
                found = true;
                cout << arr[i] << " ";
                break;
            }
        }
        if (!found)
        {
            arr3[counter++] = arr[i];
        }
    }
    for (int i = 0; i < size2; i++)
    {
        bool found = false;
        for (int j = 0; j < size1; j++)
        {
            if (arr2[i] == arr[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            arr3[counter++] = arr2[i];
        }
    }
    for (int i = 0; i < counter; i++)
    {
        cout << arr3[i] << " ";
    }
    return counter;
}