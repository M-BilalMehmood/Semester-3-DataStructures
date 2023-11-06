#include<iostream>
#include<string>
//#include"22I-2452_H2.h"
#include"22I-2452_H3.h"
using namespace std;

class Node
{
public:
    string name;
    int age;
    double salary;
    Node* next;
};

class Queue
{
private:
    Node* front;
    Node* rear;
public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(string name, int age, double salary)
    {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->salary = salary;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    void showFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Name  : " << front->name << endl;
        cout << "Age   : " << front->age << endl;
        cout << "Salary: " << front->salary << endl;
    }
    bool isEmpty()
    {
        if (front == nullptr && rear == nullptr)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr)
        {
            cout << "Name  : " << temp->name << endl;
            cout << "Age   : " << temp->age << endl;
            cout << "Salary: " << temp->salary << endl;
            cout << "--------------------------\n";
            temp = temp->next;
        }
    }
};