#pragma once
#include<iostream>
#include<string>
#include"22I-2452_LAB06_Header1.h"
using namespace std;

class CircularDoublyLinkedList
{
private:
    Node* head;
    Node* tail;
public:
    CircularDoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Display()
    {
        if (isEmpty() == true)
        {
            cout << "\033[1;31mList is empty\033[0m" << endl;
            return;
        }
        Node* current = head;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    void insertAtHead(int data)
    {
        Node* newNode = new Node(data);
        if (isEmpty() == true)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            head->prev = tail;
            tail->next = head;
        }
        cout << "\033[1;32mNode inserted successfully\033[0m" << endl;
    }

    void insertAtTail(int data)
    {
        Node* newNode = new Node(data);
        if (isEmpty() == true)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }
        cout << "\033[1;32mNode inserted successfully\033[0m" << endl;
    }

    void insertionBeforeNode(int data, int node)
    {
        Node* newNode = new Node(data);
        if (isEmpty() == true)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
            cout << "\033[1;32mNode inserted successfully\033[0m" << endl;
            return;
        }
        Node* current = head;
        while (current->data != node)
        {
            current = current->next;
            if (current == head)
            {
                cout << "\033[1;31mNode not found\033[0m" << endl;
                return;
            }
        }
        if (current == head)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            head->prev = tail;
            tail->next = head;
        }
        else
        {
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
        cout << "\033[1;32mNode inserted successfully\033[0m" << endl;
    }

    void insertionAfterNode(int data, int node)
    {
        Node* newNode = new Node(data);
        if (isEmpty() == true)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
            cout << "\033[1;32mNode inserted successfully\033[0m" << endl;
            return;
        }
        Node* current = head;
        while (current->data != node)
        {
            current = current->next;
            if (current == head)
            {
                cout << "\033[1;31mNode not found\033[0m" << endl;
                return;
            }
        }
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
        if (current == tail)
        {
            tail = newNode;
        }
        cout << "\033[1;32mNode inserted successfully\033[0m" << endl;
    }

    void DeleteTheFirstNode()
    {
        if (isEmpty() == true)
        {
            cout << "\033[1;31mList is empty\033[0m" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            delete head->prev;
            head->prev = tail;
            tail->next = head;
        }
        cout << "\033[1;32mNode deleted successfully\033[0m" << endl;
    }

    void DeleteLastNode()
    {
        if (isEmpty() == true)
        {
            cout << "\033[1;31mList is empty\033[0m" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = head;
            head->prev = tail;
        }
        cout << "\033[1;32mNode deleted successfully\033[0m" << endl;
    }

    void DeleteMiddleNode()
    {
        if (isEmpty() == true)
        {
            cout << "\033[1;31mList is empty\033[0m" << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node* current = head;
            int count = 0;
            while (current != tail)
            {
                current = current->next;
                count++;
            }
            current = head;
            for (int i = 0; i < count / 2; i++)
            {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        cout << "\033[1;32mNode deleted successfully\033[0m" << endl;
    }

    void DeleteSpecificNode(int data)
    {
        if (isEmpty() == true)
        {
            cout << "\033[1;31mList is empty\033[0m" << endl;
            return;
        }
        Node* current = head;
        while (current->data != data)
        {
            current = current->next;
            if (current == head)
            {
                cout << "\033[1;31mNode not found\033[0m" << endl;
                return;
            }
        }
        if (current == head)
        {
            DeleteTheFirstNode();
        }
        else if (current == tail)
        {
            DeleteLastNode();
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            cout << "\033[1;32mNode deleted successfully\033[0m" << endl;
        }
    }
    void Sort()
    {
        if (isEmpty() == true)
        {
            cout << "\033[1;31mList is empty\033[0m" << endl;
            return;
        }
        Node* current = head;
        Node* index = NULL;
        int temp;
        if (head == NULL)
        {
            return;
        }
        else
        {
            do
            {
                index = current->next;
                while (index != head)
                {
                    if (current->data > index->data)
                    {
                        current = index->next;
                        index->next->prev = current;
                        index->next = current;
                        current->prev = index;
                    }
                    index = index->next;
                }
                current = current->next;
            } while (current->next != head);
        }
        cout << "\033[1;32mList sorted successfully\033[0m" << endl;
    }
    void removeDuplicates()
    {
        if (isEmpty() == true)
        {
            cout << "\033[1;31mList is empty\033[0m" << endl;
            return;
        }
        Node* current = head;
        do
        {
            if (current->data == current->next->data)
            {
                Node* temp = current->next;
                current->next = temp->next;
                if (temp->next != NULL)
                {
                    temp->next->prev = current;
                }
                delete temp;
                cout << "\033[1;32mDuplicate node deleted successfully\033[0m" << endl;
            }
            else
            {
                current = current->next;
            }
        } while (current->next != head);
        cout << "\033[1;32mDuplicates removed successfully\033[0m" << endl;
    }
};