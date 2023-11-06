#include <iostream>
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
        }
        while (current != head);
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
};

int main()
{
    CircularDoublyLinkedList list;
    int choice, data, node;
    while (true)
    {
        cout << "1. Insertion at the beginning of list" << endl;
        cout << "2. Insertion after a node" << endl;
        cout << "3. Insertion at the end of list" << endl;
        cout << "4. Insertion before a node" << endl;
        cout << "5. Delete the first node" << endl;
        cout << "6. Delete the middle node" << endl;
        cout << "7. Delete the last node" << endl;
        cout << "8. Delete a specific node" << endl;
        cout << "9. Display all elements of the list" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            list.insertAtHead(data);
            break;
        case 2:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter the node after which you want to insert: ";
            cin >> node;
            list.insertionAfterNode(data, node);
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            list.insertAtTail(data);
            break;
        case 4:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter the node before which you want to insert: ";
            cin >> node;
            list.insertionBeforeNode(data, node);
            break;
        case 5:
            list.DeleteTheFirstNode();
            break;
        case 6:
            list.DeleteMiddleNode();
            break;
        case 7:
            list.DeleteLastNode();
            break;
        case 8:
            cout << "Enter data: ";
            cin >> data;
            list.DeleteSpecificNode(data);
            break;
        case 9:
            list.Display();
            break;
        case 10:
            exit(0);
        default:
            cout << "\033[1;31mInvalid choice\033[0m" << endl;
            break;
        }
    }
    return 0;
}