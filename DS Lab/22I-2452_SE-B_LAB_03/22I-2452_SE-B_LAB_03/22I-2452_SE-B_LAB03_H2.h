#pragma once
#include<iostream>
#include<string>
using namespace std;

void search(string ouch, char no)
{
	bool flag = false;
	for (int i = 0; i < ouch.length(); i++)
	{
		if (ouch[i] == no)
		{
			flag = true;
			cout << "Output: ";
			for (int j = i; j < ouch.length(); j++)
			{
				cout << ouch[j];
			}
			cout << endl;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Character not found!" << endl;
	}
}