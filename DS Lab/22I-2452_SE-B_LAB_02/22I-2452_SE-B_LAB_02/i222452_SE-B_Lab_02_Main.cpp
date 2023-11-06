#include<iostream>
#include<string>
#include"I222452_SE-B_LAB_02_Header1.h"
using namespace std;

int main()
{
	cout << "Smaller of 'a' and 'B' : " << if_smaller('a', 'B') << endl;
	cout << "Smaller of 12 and 15 : " << if_smaller(12, 15) << endl;
	cout << "Smaller of 44.2 and 33.1 : " << if_smaller(44.2, 33.1) << endl;
	cout << "===============================" << endl;
	cout << "Smaller of 'A', 'b' and 'c' : " << if_smaller('A', 'a', 'c') << endl;
	cout << "Smaller of 2, 4, 10 : " << if_smaller(2, 4, 10) << endl;
	cout << "Smaller of 2.1, 4.1, 10.1 : " << if_smaller(2.1, 4.1, 10.1) << endl;
	cout << "===============================" << endl;
	cout << "Enter the size for arr1: "; int n; cin >> n;
	int* arr1 = new	int[n];
	cout << "Enter the elements for arr1: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}
	cout << "Enter the size for arr2: "; int m; cin >> m;
	int* arr2 = new	int[n];
	cout << "Enter the elements for arr2: ";
	for (int j = 0; j < m; j++)
	{
		cin >> arr2[j];
	}
	int* arr3 = new int [n + m];
	comparison(arr1, arr2, arr3, n, m);
	cout << "===============================" << endl;
	cout << "Enter the size for arr1: "; int n1; cin >> n1;
	//Box b;
	return 0;
}