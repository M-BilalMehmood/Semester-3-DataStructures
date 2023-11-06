#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    char Input;
    Node* next;
public:
    Node()
    {
        Input = ' ';
        next = NULL;
    }
    Node(char Input)
    {
        this->Input = Input;
        next = NULL;
    }
    void setInput(char Input)
    {
        this->Input = Input;
    }
    void setNext(Node* next)
    {
        this->next = next;
    }
    char getInput()
    {
        return Input;
    }
    Node* getNext()
    {
        return next;
    }

};

class Alphabet_Queue
{
private:
    Node* front;
    Node* rear;
public:
    Alphabet_Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(char Input)
    {
        Node* temp = new Node(Input);
        if (front == NULL && rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->setNext(temp);
        rear = temp;
    }
    void dequeue()
    {
        if (front == NULL)
            return;
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            Node* temp = front;
            front = front->getNext();
            delete temp;
        }
    }
    char getFront()
    {
        if (front == NULL)
            return ' ';
        return front->getInput();
    }
    bool isEmpty()
    {
        if (front == NULL)
            return true;
        return false;
    }
    void printQueue()
    {
        Node* temp = front;
        while (temp != NULL)
        {
            cout << temp->getInput();
            temp = temp->getNext();
        }
        cout << endl;
    }
};

class QueueED {
private:
    Alphabet_Queue alphabet;
    Alphabet_Queue arithmetic;
    Alphabet_Queue number;
public:
    void decryptPassword(string password) {
        for (int i = 0; i < password.length(); i++) {
            char c = password[i];
            if (isalpha(c)) {
                alphabet.enqueue(c);
            }
            else if (isdigit(c)) {
                number.enqueue(c);
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                arithmetic.enqueue(c);
            }
        }
        while (!arithmetic.isEmpty()) {
            char op = arithmetic.getFront();
            int result = 0;
            if (op == '*') {
                result = (number.getFront() - '0') * (number.getFront()->getNext()->getInput() - '0');
            }
            else if (op == '/') {
                result = (number.getFront() - '0') / (number.getFront()->getNext()->getInput() - '0');
            }
            number.dequeue();
            number.dequeue();
            number.enqueue(result + '0');
            arithmetic.dequeue();
        }
        alphabet.printQueue();
        number.printQueue();
        arithmetic.printQueue();
    }
};