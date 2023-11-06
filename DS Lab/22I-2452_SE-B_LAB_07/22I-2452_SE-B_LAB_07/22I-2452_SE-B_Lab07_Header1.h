#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"22I-2452_SE-B_Lab07_Header3.h"
using namespace std;

class Node
{
public:
	int data;
	Node* joor;
	Node(int data)
	{
		this->data = data;
		joor = NULL;
	}
};

class Stack
{
private:
	Node* top;
public:
	Stack()
	{
		top = NULL;
	}
	void push(int data)
	{
		Node* temp = new Node(data);
		if (top == NULL)
		{
			top = temp;
		}
		else
		{
			temp->joor = top;
			top = temp;
		}
	}
	int pop()
	{
		if (top == NULL)
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		else
		{
			Node* temp = top;
			top = top->joor;
			int data = temp->data;
			delete temp;
			return data;
		}
	}
	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int peek()
	{

		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
			return -1;
		}
		else
		{
			return top->data;
		}
	}
	~Stack()
	{
		//cout << "Stack is destroyed" << endl;
	}
};