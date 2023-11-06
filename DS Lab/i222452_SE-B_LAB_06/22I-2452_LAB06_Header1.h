#pragma once
#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};