#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include"22I-2452_SE-B_Lab07_Header1.h"
using namespace std;

void Task1();
void Task2();
void Task3();

int main()
{
	cout << "WELCOME TO LAB 7" << endl;
	cout << "----------------" << endl;
	cout << "Which task do you want to perform?" << endl;
	cout << "1. Task 1" << endl;
	cout << "2. Task 2" << endl;
	cout << "3. Task 3" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			Task1();
			break;
		}
		case 2:
		{
			Task2();
			while (true)
			{
				cout << "Do you want to perform another task? (y/n): ";
				char ch;
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					Task2();
				}
				else if (ch == 'n' || ch == 'N')
				{
					system("cls");
					main();
				}
				else
				{
					cout << "Invalid choice" << endl;
				}
			}
			break;
		}
		case 3:
		{
			Task3();
			break;
		}
		case 4:
		{
			exit(0);
		}
		default:
		{
			cout << "Invalid choice" << endl; 
		}
	}
}

void Task1()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << "Peek element is: " << s.peek() << endl;
	s.pop();
	cout << "top element poped" << endl;
	cout << "Peek element is: " << s.peek() << endl;
	s.pop();
	cout << "top element poped" << endl;
	cout << "Peek element is: " << s.peek() << endl;
	s.pop();
	cout << "top element poped" << endl;
	cout << "Peek element is: " << s.peek() << endl;
	cout << "Is Stack empty: ";
	s.pop();
	if (s.isEmpty())
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}

void Task2()
{
	string equation;
	cout << "Enter the equation: ";
	cin >> equation;
	Stack s;
	for (int i = 0; i < equation.length(); i++)
	{
		char c = equation[i];
		if (c == '(' || c == '[' || c == '{') {
			s.push(c);
		}
		else if (c == ')' || c == ']' || c == '}')
		{
			if (s.isEmpty())
			{
				cout << "The string brackets are not balanced" << endl;
			}
			char top = s.peek();
			if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{'))
			{
				s.pop();
			}
			else
			{
				cout << "The string brackets are not balanced" << endl;
			}
		}
	}
	cout << "The string brackets are balanced" << endl;
}

void readfile()
{
	ifstream fin("file.csv");
	if (fin.is_open())
	{
		string line;
		while (getline(fin, line))
		{
			Student st;
			stringstream ss(line);
			string data;
			getline(ss, data, ',');
			st.setSrno(stoi(data));
			getline(ss, data, ',');
			st.setRegdate(data);
			getline(ss, data, ',');
			st.setName(data);
			getline(ss, data, ',');
			st.setRollno(data);
			getline(ss, data, ',');
			st.setA1(stoi(data));
			getline(ss, data, ',');
			st.setA2(stoi(data));
			getline(ss, data, ',');
			st.setA3(stoi(data));
			getline(ss, data, ',');
			st.setA4(stoi(data));
			getline(ss, data, ',');
			st.setAs(stoi(data));
			getline(ss, data, ',');
			st.setS1(stoi(data));
			getline(ss, data, ',');
			st.setS2(stoi(data));
			getline(ss, data, ',');
			st.setProj(stoi(data));
			getline(ss, data, ',');
			st.setProj1(stoi(data));
			getline(ss, data, ',');
			st.setFinal1(stoi(data));
			getline(ss, data, ',');
			st.setFinal2(stoi(data));
			getline(ss, data, ',');
			st.setMid1(stoi(data));
			getline(ss, data, ',');
			st.setMid2(stoi(data));
			getline(ss, data, ',');
			st.setGtotal(stoi(data));
			//s.push(st);
		}
		fin.close();
	}
	else
	{
		cout << "File not found" << endl;
	}
}


void readCSVfile()
{
	ifstream fin("file.csv");
	if (fin.is_open())
	{
		string line;
		while (fin >> line)
		{
			cout << line << endl;
		}
		fin.close();
	}
	else
	{
		cout << "File not found" << endl;
	}
}
void saveToFile(Student* stdData, int size, string filename)
{
	ofstream fout(filename);
	if (fout.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			fout << stdData[i].getSrno() << ","
				<< stdData[i].getRegdate() << ","
				<< stdData[i].getName() << ","
				<< stdData[i].getRollno() << ","
				<< stdData[i].getA1() << ","
				<< stdData[i].getA2() << ","
				<< stdData[i].getA3() << ","
				<< stdData[i].getA4() << ","
				<< stdData[i].getAs() << ","
				<< stdData[i].getS1() << ","
				<< stdData[i].getS2() << ","
				<< stdData[i].getProj() << ","
				<< stdData[i].getProj1() << ","
				<< stdData[i].getFinal1() << ","
				<< stdData[i].getFinal2() << ","
				<< stdData[i].getMid1() << ","
				<< stdData[i].getMid2() << ","
				<< stdData[i].getGtotal() << endl;0
		}
		fout.close();
	}
	else
	{
		cout << "Error: could not open file " << filename << endl;
	}
}

void Task3()
{
	readCSVfile();
}