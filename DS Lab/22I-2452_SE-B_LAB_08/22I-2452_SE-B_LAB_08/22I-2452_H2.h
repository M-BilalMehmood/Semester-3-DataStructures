#include <iostream>
#include <string>
using namespace std;

void running();

class QueueED {
private:
    char* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    QueueED(int size) {
        arr = new char[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~QueueED() {
        delete[] arr;
    }

    void enqueue(char item) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    char dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return '\0';
        }
        char item = arr[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return '\0';
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

string decryptPassword(string password) {
    QueueED alphabetQueue(password.length());
    QueueED numberQueue(password.length());
    QueueED arithmeticQueue(password.length());

    for (int i = 0; i < password.length(); i++) {
        char c = password[i];
        if (isalnum(c)) {
            if (isdigit(c)) {
                numberQueue.enqueue(c);
            }
            else {
                alphabetQueue.enqueue(c);
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            arithmeticQueue.enqueue(c);
        }
    }

    while (!arithmeticQueue.isEmpty()) {
        char op = arithmeticQueue.peek();
        int a = numberQueue.dequeue() - '0';
        int b = numberQueue.dequeue() - '0';
        int result;
        switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        }
        numberQueue.enqueue(result + '0');
        arithmeticQueue.dequeue();
    }

    string decryptedPassword = "";
    while (!alphabetQueue.isEmpty()) {
        decryptedPassword += alphabetQueue.dequeue();
    }
    while (!numberQueue.isEmpty()) {
        decryptedPassword += numberQueue.dequeue();
    }
    while (!arithmeticQueue.isEmpty()) {
        decryptedPassword += arithmeticQueue.dequeue();
    }

    return decryptedPassword;
};

void runnning()
{
    string password;
    cout << "Enter encrypted password: ";
    cin >> password;
    string decryptedPassword = decryptPassword(password);
    cout << "Decrypted password: " << decryptedPassword << endl;
}