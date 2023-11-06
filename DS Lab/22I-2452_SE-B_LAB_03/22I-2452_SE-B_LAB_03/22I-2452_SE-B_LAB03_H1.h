#pragma once
#include<iostream>
#include<string>
#include"22I-2452_SE-B_LAB03_H2.h"
#include"22I-2452_SE-B_LAB03_H3.h"
using namespace std;

int min(int* a, int size)
{
	int min = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}
int max(int* a, int size)
{
	int max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}