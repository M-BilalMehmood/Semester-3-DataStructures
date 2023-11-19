/*
    Name; Muhammad Bilal Mehmood
    Roll No: 22I-2452
    Section: B
    Assignment: 3
*/
#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

void smile() //Just a smiley face ^_^
{
    cout << "  _____  " << endl;
    cout << " /     \\ " << endl;
    cout << "| _   _ |" << endl;
    cout << "|   .   |" << endl;
    cout << "| \\___/ |" << endl;
    cout << " \\_____/ " << endl;
}

int main()
{
    // Varaibles for user input
    Tree tree;
    string input;
    string type;
    string command;
    string name;
    string path;
    string source, destination;
    smile();
    // Sample data
    // tree.createDirectory("P1", "/PatientsData");
    // tree.createFile("11.txt", "/PatientsData/P1");
    // tree.createDirectory("P2", "/PatientsData");
    // tree.createFile("21.txt", "/PatientsData/P1/P2");
    // tree.createDirectory("L1", "/Logs");
    // tree.createDirectory("L2", "/Logs");
    // tree.createDirectory("L3", "/Logs");
    // tree.createFile("33.txt", "/Logs/L1/L2/L3");
    while (true)
    {
        cout << "\033[1;36mEnter a command: \033[33m";
        getline(cin, input);
        stringstream ss(input);
        ss >> command;
        cout << "\033[0m";
        //make directory
        if (command == "mkdir")
        {
            ss >> name;
            ss >> path;
            tree.createDirectory(name, path);
        }
        //make file
        else if (command == "touch")
        {
            ss >> name;
            ss >> path;

            // Check if the filename has an extension
            size_t dotPos = name.find_last_of('.');
            if (dotPos == string::npos || dotPos == name.length() - 1) 
            {
                cout << "\e[1;41mError: Filename must have an extension (e.g., .txt or .pdf).\033[0m" << endl;
                continue;
            }

            string extension = name.substr(dotPos + 1);
            if (extension != "txt" && extension != "pdf") 
            {
                cout << "\e[1;41mError: Invalid file extension.\033[0m" << endl;
                continue;
            }

            tree.createFile(name, path);
        }
        //copy file
        else if (command == "copy")
        {
            ss >> source;
            ss >> destination;
            tree.copyFile(source, destination);
        }
        //move file
        else if (command == "move")
        {
            ss >> source;
            ss >> destination;
            tree.moveFile(source, destination);
        }
        //list directory
        else if (command == "ls")
        {
            ss >> path;
            tree.listDirectoryTree();
        }
        //merge directory
        else if (command == "merge")
        {
            ss >> source;
            ss >> destination;
            tree.mergeDirectories(source, destination);
        }
        //delete directory
        else if (command == "rmdir")
        {
            ss >> name;
            ss >> path;
            tree.deleteFolder(name, path);
        }
        //deleteFile
        else if (command == "rmfile")
        {
            ss >> name;
            ss >> path;
            tree.deleteFile(name, path);
        }
        //search file
        else if (command == "search")
        {
            ss >> name;
            tree.searchFile(name, "");
        }
        //clear screen
        else if (command == "cls")
        {
            system("cls");
            smile();
        }
        //exit
        else if (command == "exit")
        {
            break;
        }
        //print
        else if (command == "print")
        {
            tree.printTree();
        }
        //export
        else if (command == "export")
        {
            ss >> name;
            tree.exportT(name);
        }
        //import
        else if (command == "import")
        {
            ss >> name;
            tree.importT(name);
        }
        //print left right
        else if (command == "plr")
        {
            ss >> name;
            tree.printLeftRightNodes(name);
        }
        //print left and right child nodes
        else
        {
            cout << "\e[1;41mInvalid command.\033[0m" << endl;
        }
    }

    return 0;
}