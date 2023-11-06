#include<iostream>
#include<string>
#include"Header.h"
using namespace std;

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
        cout << "10. Sort the list" << endl;
        cout << "11. Remove Duplicate" << endl;
        cout << "12. Exit" << endl;
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
            list.Sort();
            break;
        case 11:
            list.removeDuplicates();
            break;
        case 12:
            exit(0);
        default:
            cout << "\033[1;31mInvalid choice\033[0m" << endl;
            break;
        }
    }
    return 0;
}