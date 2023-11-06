#pragma once
#include<iostream>
#include<string>
using namespace std;

#include <iostream>
#include <string>

class Queue32 {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue32(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue32() {
        delete[] arr;
    }

    void enqueue(int item) 
    {
        if (isFull()) 
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    int dequeue() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    int peek() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int size() 
    {
        return count;
    }

    bool isEmpty() 
    {
        return (size() == 0);
    }

    bool isFull() 
    {
        return (size() == capacity);
    }
};

void roundRobin(Queue32& executionTime, int quantum) 
{
    Queue32 remainingTime(executionTime.size());
    int n = executionTime.size();
    int time = 0;
    int completed = 0;

    while (!executionTime.isEmpty() || !remainingTime.isEmpty()) 
    {
        if (!remainingTime.isEmpty()) 
        {
            int task = remainingTime.peek();
            remainingTime.dequeue();
            if (task <= quantum) 
            {
                time += task;
                cout << "Task " << n - executionTime.size() << " completed at time " << time << endl;
                completed++;
            }
            else 
            {
                time += quantum;
                task -= quantum;
                remainingTime.enqueue(task);
            }
        }
        else 
        {
            int task = executionTime.peek();
            executionTime.dequeue();
            if (task <= quantum) 
            {
                time += task;
                cout << "Task " << n - executionTime.size() << " completed at time " << time << endl;
                completed++;
            }
            else 
            {
                time += quantum;
                task -= quantum;
                remainingTime.enqueue(task);
            }
        }
    }
    cout << "All tasks completed in " << time << " units of time." << endl;
}