#pragma once
#include<iostream>
#include<string>
#include"22I-2452_SE-B_LAB_05_H2.h"
using namespace std;

class LinkedList
{
private:
    Node* head;
    Node* tail;
public:
    LinkedList()
    {
        //create an empty linked list
        head = nullptr;
        tail = nullptr;
    }
    LinkedList(Node* ptr)
    {
        head = ptr;
        tail = ptr;
    }
    LinkedList(LinkedList& list)
    {
        head = list.head;
        tail = list.tail;
    }

    //setters
    void setHead(Node* ptr) { head = ptr; }
    void setTail(Node* ptr) { tail = ptr; }
    //getters
    Node* getHead() { return head; }
    Node* getTail() { return tail; }

    //functions
    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insert(const Employee& emp)
    {
        Employee emmp = emp;
        Node* newNode = new Node(emmp);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->setNext(newNode);
            tail = newNode;
        }
    }
    void remove(int id)
    {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr)
        {
            if (current->getData().getEmpID() == id)
            {
                if (previous == nullptr)
                {
                    // Removing the head node
                    head = current->getNext();
                }
                else
                {
                    previous->setNext(current->getNext());
                }
                delete current;
                cout << "\033[1;31mRecord removed\033[0m" << endl;
                return;
            }
            previous = current;
            current = current->getNext();
        }
    }
    void UpdateSalary(const int& salary, int id)
    {
        Node* current = head;
        if (isEmpty() == false)
        {
            while (current != nullptr)
            {
                if (current->getData().getEmpID() == id)
                {
                    current->getData().setSalary(salary);
                    cout << "\033[1;33mSalary updated\033[0m" << endl;
                    return;
                }
                current = current->getNext();
            }
        }
        cout << endl << "\033[1;31mRecord not Found\033[0m" << endl;
    }
    void UpdateBonus(const int& Bonus, int id)
    {
        Node* current = head;
        if (isEmpty() == false)
        {
            while (current != nullptr)
            {
                if (current->getData().getEmpID() == id)
                {
                    current->getData().setBonus(Bonus);
                    cout << "\033[1;32mBonus updated\033[0m" << endl;
                    return;
                }
                else
                {
                    current = current->getNext();
                }
            }
        }
        cout << endl << "\033[1;31mRecord not Found\033[0m" << endl;
    }
    void clear()
    {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr)
        {
            next = current->getNext();
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }
    void Display()
    {
        if (isEmpty() == false)
        {
            Node* current = head;
            while (current != nullptr)
            {
                current->getData().displayDetails();
                current = current->getNext();
            }
        }
        else
        {
            cout << "\033[1;31mList is empty\033[0m" << endl;
        }
    }
    void sort()
    {
        Node* current = head;
        Node* index = nullptr;
        Employee temp;
        if (isEmpty() == false)
        {
            while (current != nullptr)
            {
                index = current->getNext();
                while (index != nullptr)
                {
                    if (current->getData().getSalary() > index->getData().getSalary())
                    {
                        temp = current->getData();
                        current->setData(index->getData());
                        index->setData(temp);
                    }
                    index = index->getNext();
                }
                current = current->getNext();
            }
        }
        else
        {
            cout << "\033[1;31mList is empty\033[0m" << endl;
        }
    }
    ~LinkedList()
    {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr)
        {
            next = current->getNext();
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        //Destructor
    }
};