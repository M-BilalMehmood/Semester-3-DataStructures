#pragma once
#include<iostream>
#include<string>
using namespace std;

#include <iostream>
#include <string>

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[front];
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return (size() == 0);
    }

    bool isFull() {
        return (size() == capacity);
    }
};

void roundRobin(Queue& executionTime, int quantum) {
    Queue remainingTime(executionTime.size()); // to store remaining execution time of tasks
    int n = executionTime.size(); // number of tasks
    int time = 0; // current time
    int completed = 0; // number of completed tasks

    while (!executionTime.isEmpty() || !remainingTime.isEmpty()) {
        if (!remainingTime.isEmpty()) {
            int task = remainingTime.peek();
            remainingTime.dequeue();
            if (task <= quantum) {
                time += task;
                std::cout << "Task " << n - executionTime.size() << " completed at time " << time << std::endl;
                completed++;
            }
            else {
                time += quantum;
                task -= quantum;
                remainingTime.enqueue(task);
            }
        }
        else {
            int task = executionTime.peek();
            executionTime.dequeue();
            if (task <= quantum) {
                time += task;
                std::cout << "Task " << n - executionTime.size() << " completed at time " << time << std::endl;
                completed++;
            }
            else {
                time += quantum;
                task -= quantum;
                remainingTime.enqueue(task);
            }
        }
    }
    std::cout << "All tasks completed in " << time << " units of time." << std::endl;
}