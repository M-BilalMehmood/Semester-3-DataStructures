#include<iostream>
#include"22I-2452_Header1.h"
using namespace std;

int main()
{
	Tree t;
	cout << "The Value in Tree is: ";
	t.insert(10); t.insert(20); t.insert(5); t.insert(30); t.insert(15); t.insert(25); t.insert(35);
	t.inorder();
	cout << endl << "TREE: " << endl;
	cout << "\033[32m             10                  " << endl;
	cout << "\033[36m            /  \\                " << endl;
	cout << "\033[32m           5   20                " << endl;
	cout << "\033[36m              /  \\              " << endl;
	cout << "\033[32m             15  30              " << endl;
	cout << "\033[36m                /  \\            " << endl;
	cout << "\033[32m               25  35     \033[0m" << endl;
	cout << endl;
	cout << "\033[36mWELCOME TO DEPRESSION MANIA\033[0m" << endl;
	cout << "\033[32m[1] Find the height of BST\033[0m" << endl;
	cout << "\033[32m[2] Find the Depth of Node in a BST\033[0m" << endl;
	cout << "\033[32m[3] Count the nodes in the range\033[0m" << endl;
	cout << "\033[32m[4] Find the Kth smallest value in BST\033[0m" << endl;
	cout << "\033[31m[5] EXIT\033[0m" << endl << ":^_^: ";
	int n; cin >> n;
	if (n == 1)
	{
		cout << "Height of tree: \033[32m" << t.getHeight() - 1 << endl;
		cout << "\033[0mPress ENTER to continue..." << endl;
		cin.ignore();
		cin.get();
		system("cls");
		main();
	}
	else if (n == 2)
	{
		cout << "Enter the value to find the depth of that node: ";
		int val; cin >> val;
		cout << "Depth of node with value " << val << " : \033[32m" << t.findDepth(val) << endl;
		cout << "\033[0mPress ENTER to continue..." << endl;
		cin.ignore();
		cin.get();
		system("cls");
		main();
	}
	else if (n == 3)
	{
		//cout << "::> Range <::" << endl;
		cout << "Enter the starting value: ";
		int val1; cin >> val1;
		cout << "Enter the ending value: ";
		int val2; cin >> val2;
		cout << "Number of nodes in range [" << val1 << ", " << val2 << "]: \033[32m" << t.countRange(val1, val2) << endl;
		cout << "\033[0mPress ENTER to continue..." << endl;
		cin.ignore();
		cin.get();
		system("cls");
		main();
	}
	else if (n == 4)
	{
		cout << "Enter the smallest element that you want to find: ";
		int smallval; cin >> smallval;
		cout << "The " << smallval << "th smallest value is : \033[32m" << t.GOkthSmallest(smallval) << endl;
		cout << "\033[0mPress ENTER to continue..." << endl;
		cin.ignore();
		cin.get();
		system("cls");
		main();
	}
	else if (n == 5)
	{
		cout << "\033[36mHave a great depressing life!\033[0m" << endl;
		exit(0);
	}
	else
	{
		cout << "\033[31mInvalid Entry" << endl;
		cout << "\033[0mPress ENTER to continue..." << endl;
		cin.ignore();
		cin.get();
		system("cls");
		main();
	}
}