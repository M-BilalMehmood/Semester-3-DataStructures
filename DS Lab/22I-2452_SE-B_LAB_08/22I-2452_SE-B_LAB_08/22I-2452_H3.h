#pragma once
#include<iostream>
using namespace std;

class QueueED {
private:
    string data;
public:
    void enqueue(char c) {
        data += c;
    }
    void dequeue() {
        if (!isEmpty()) {
            data.erase(0, 1);
        }
    }
    char getFront() {
        if (!isEmpty()) {
            return data[0];
        }
        return ' ';
    }
    bool isEmpty() {
        return data.empty();
    }
    void printQueue() {
        cout << data << endl;
    }
};

class Stack {
private:
    QueueED q1, q2;
public:
    void push(char c) {
        q2.enqueue(c);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.getFront());
            q1.dequeue();
        }
        swap(q1, q2);
    }
    void pop() {
        if (!q1.isEmpty()) {
            q1.dequeue();
        }
    }
    char top() {
        if (!q1.isEmpty()) {
            return q1.getFront();
        }
        return ' ';
    }
    bool empty() {
        return q1.isEmpty();
    }
};