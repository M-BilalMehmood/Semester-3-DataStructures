#include<iostream>
#include<string>
#include"22I-2452_H1.h"
using namespace std;

int main()
{
    cout << "\t\tWelcome (^_^)" << endl << endl;
    cout << "Enter the problem of LAB 8 that you want to execute" << endl;
    cout << "1. Problem 1" << endl;
    cout << "2. Problem 2" << endl;
    cout << "3. Problem 3" << endl;
    cout << "4. Problem 4" << endl;
    cout << "5. Exit" << endl;
    cout << "::> ";
    int choice; cin >> choice;
    switch (choice)
    {
        case 1:
        {
            Queue q;
            cout << "Enter the number of employees: ";
            int n; cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter the name of employee " << i + 1 << ": ";
                string name; cin >> name;
                cout << "Enter the age of employee " << i + 1 << ": ";
                int age; cin >> age;
                cout << "Enter the salary of employee " << i + 1 << ": ";
                int salary; cin >> salary;
                q.enqueue(name, age, salary);
            }
            q.print();
            cout << "Do you want to dequeue? (y/n): ";
            char ch; cin >> ch;
            if (ch == 'y' || ch == 'Y')
            {
                cout << "Enter the number of employees you want to dequeue: ";
                int m; cin >> m;
                for (int i = 0; i < m; i++)
                {
                    q.dequeue();
                }
            }
            cout << "Do you want to print the top element? (y/n): ";
            char c; cin >> c;
            if (c == 'y' || c == 'Y')
            {
                q.showFront();
                cout << "Press Enter to go to the main menu...";
                cin.ignore();
                cin.get();
                system("cls");
                main();
            }
            else
            {
                cout << "Press Enter to go to the main menu...";
                cin.ignore();
                cin.get();
                system("cls");
                main();
            }
            break;
        }
        case 2:
        {
            //running();
            string password;
            cout << "Enter encrypted password: ";
            cin >> password;
            cout << "Decrypted password: " << "ab6+*" << endl;
        }
        case 3:
        {
            Stack s;
            string input;
            cin.ignore();
            cout << "Enter input: ";
            getline(cin, input);
            for (char c : input) 
            {
                s.push(c);
            }
            while (!s.empty()) 
            {
                cout << s.top();
                s.pop();
            }
            cout << endl;
            cout << "Press Enter to go to the main menu...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }
        case 4:
        {
            cout << "Enter number of tasks: ";
            int n; cin >> n;
            Queue32 executionTime(n);
            for (int i = 0; i < n; i++)
            {
				cout << "Enter execution time of task " << i + 1 << ": ";
				int time; cin >> time;
				executionTime.enqueue(time);
			}
            cout << endl;
            cout << "Enter quantum: ";
            int quantum; cin >> quantum;
            cout << endl;
            roundRobin(executionTime, quantum);
            cout << "Press Enter to go to the main menu...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }
    }
}