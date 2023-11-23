#include<iostream>
#include"Header.h"
using namespace std;

int main()
{
    // AVLTree t;
    // t.print();
    AVLTree t;
    t.loadDictionary("dictionary.txt");
    string filename, prefix, word;
    int choice;

    while (true) 
    {
        cout << "Menu:" << endl;
        cout << "1. Load dictionary" << endl;
        cout << "2. Autocomplete" << endl;
        cout << "3. Delete Word" << endl;
        cout << "4. Print Dictionary" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter filename: ";
                cin >> filename;
                t.loadDictionary(filename);
                break;
            case 2:
                cout << "Enter prefix: ";
                cin >> prefix;
                cout << "Autocomplete suggestions:\n";
                t.autocomplete(prefix);
                break;
            case 3:
                cout << "Enter word to delete: ";
                cin >> word;
                t.deleteWord(word);
                break;
            case 4:
                cout << "All words in the dictionary:\n";
                t.print();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}