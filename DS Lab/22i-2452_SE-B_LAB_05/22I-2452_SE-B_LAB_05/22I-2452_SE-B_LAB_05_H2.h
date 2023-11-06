#pragma once
#include<iostream>
#include<string>
#include"22I-2452_SE-B_LAB_05_H1.h"
using namespace std;

class Node
{
private:
    Employee data;
    Node* next;
public:
    Node() : next(nullptr) {};
    Node(Employee& emp)
    {
        data = emp;
        next = nullptr;
    }
    Node(Employee& emp, Node* ptr)
    {
        data = emp;
        next = ptr;
    }

    //setters
    void setData(Employee& emp) { data = emp; }
    void setNext(Node* ptr) { next = ptr; }
    //getters
    Employee& getData() { return data; }
    Node* getNext() { return next; }

    ~Node()
    {
        //Destructor
    }
};