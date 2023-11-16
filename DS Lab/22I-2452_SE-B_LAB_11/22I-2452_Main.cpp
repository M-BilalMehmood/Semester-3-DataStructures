#include<iostream>
#include<string>
#include"22I-2452_Header1.h"
using namespace std;

int main()
{
    Tree t;
    cout << "\033[32m             10                  " << endl;
    cout << "\033[36m            /  \\                " << endl;
    cout << "\033[32m           5   20                " << endl;
    cout << "\033[36m              /  \\              " << endl;
    cout << "\033[32m             15  30              " << endl;
    cout << "\033[36m                /  \\            " << endl;
    cout << "\033[32m               25  35     \033[0m" << endl;
    cout << "Enter the number of elements you want to insert: ";
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        int data; cin >> data;
        t.insert(data);
    }
    t.print();
}