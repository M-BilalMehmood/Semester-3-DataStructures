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
    cout << endl;
    t.print();
    cout << endl;
    int m;
    while(m != 5)
    {
        cout << "\033[32mSelect the action that you want to perform: \033[0m" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Print Tree" << endl;
        cout << "4. Exit" << endl;
        cout << "::> "; 
        cin >> m;
        if (m == 1)
        {
            cout << "How many values do you want to enter: ";
            int s; cin >> s;
            for (int i = 0; i < s; i++)
            {
                cout << i + 1 << ": ";
                int data; cin >> data;
                t.insert(data);
            }
            cout << "Data entered successfully" << endl;
        }
        else if (m == 2)
        {
            cout << "Enter the number that you want to delete: ";
            int s; cin >> s;
            t.deleting(s);
        }
        else if (m == 3)
        {
            t.print();
        }
        else if(m == 4)
        {
            cout << "BYE BYEEEEE";
            exit(0);
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }
    }
}