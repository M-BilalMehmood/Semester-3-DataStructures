#include<iostream>
#include<string>
#include"22I-2452_SE-B_LAB03_H1.h"
using namespace std;

int main()
{
	cout << "Which task do you want to run (1, 2, 3): ";
	int n; cin >> n;
	switch (n)
	{
		case 1:
		{
			cout << "Kindly, enter the size of array (Greater the 10): ";
			int size = 0;
			while (size < 10)
			{
				cin >> size;
				if (size < 10)
				{
					cout << "Size smaller then 10. Enter Again! \n=>";
				}
				else
				{
					break;
				}
			}
			int* arr1 = new int[size];
			cout << endl << "kindly, enter the data :";
			for (int i = 0; i < size; i++)
			{
				cin >> arr1[i];
			}
			int minimum_val = min(arr1, size);
			int maximum_val = max(arr1, size);
			cout << endl;
			cout << "The minimum and maximum values are : ( " << minimum_val << " , " << maximum_val << " )" << endl;
			break;
		}
		case 2:
		{
			cout << "Enter a string: ";
			string ouch; cin >> ouch;
			cout << "Enter a charachter to search for: ";
			char no; cin >> no;
			search(ouch, no);
			break;
		}
		case 3:
		{
			int row, col;
			cout << "Enter number of words: ";
			cin >> row;
			cout << "Enter maximum length of word: ";
			cin >> col;
			char** sentence = words_to_sentence(row, col);
			
			for (int i = 0; i < row; i++)
			{
				cout << sentence[i] << " ";
			}
			/*for (int i = 0; i < row; i++)
			{
				delete[] sentence[i];
			}
			delete[] sentence;*/
			break;
		}
		default:
		{
			cout << "Wrong Input! Try again.";
			main();
		}
	}
}