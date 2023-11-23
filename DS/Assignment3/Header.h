/*
    Name; Muhammad Bilal Mehmood
    Roll No: 22I-2452
    Section: B
    Assignment: 3
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Node;

class QueueNode     // queue node class used for level order traversal
{
public:
    Node* data;
    QueueNode* next;

    QueueNode(Node* data) : data(data), next(nullptr) {}
};

class Queue     // queue class used for level order traversal
{
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(Node* x) 
    {
        QueueNode* temp = new QueueNode(x);

        if (rear == nullptr) 
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue() 
    {
        if (front == nullptr)
            return;

        QueueNode* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    Node* getFront() 
    {
        if (front != nullptr)
            return front->data;
        else
            return nullptr;
    }

    bool isEmpty() 
    {
        return front == nullptr;
    }
};


class Node 
{
public:
    string name;
    string path;
    string type;
    Node* leftChild;
    Node* rightChild;
    Node(string name, string path, string type) : name(name), path(path), type(type), leftChild(NULL), rightChild(NULL) {}
};

class Tree 
{
private:
    Node* root;
public:
    Tree() 
    {
        root = new Node("/", "", "directoryS");
        root->leftChild = new Node("PatientsData", "/", "directoryM");
        root->rightChild = new Node("Logs", "/", "directoryM");
    }

    void createDirectory(string name, string path)  // create directory in tree by name and path
    {
        // Find the parent node
        Node* parentNode = findParentNode(path);
        if (parentNode == NULL) 
        {
            cout << "\e[1;41mInvalid path: \033[34m" << path << "\033[0m" << endl;
            return;
        }
        if (parentNode->name == "/")
        {
            cout << "\e[1;41mInvalid path:\e[0;34m " << path << "\e[0m" << endl;
            return;
        }

        // Check if a directory with the same name already exists
        Node* currentNode2 = parentNode->leftChild;
        while (currentNode2 != NULL) 
        {
            if (currentNode2->name == name) 
            {
                cout << "\e[31mA directory with the same name already exists.\e[0m" << endl;
                return;
            }
            currentNode2 = currentNode2->leftChild;
        }

        Node* currentNode = parentNode->leftChild;
        if (currentNode == NULL) 
        {
            parentNode->leftChild = new Node(name, path + "/" + name, "directory");
            return;
        }
        while (currentNode->leftChild != NULL) 
        {
            currentNode = currentNode->leftChild;
        }
        currentNode->leftChild = new Node(name, path + "/" + name, "directory");
        cout << "\e[1;32mDirectory created successfully.\e[0m" << endl;
    }

    void createFile(string name, string path)  // create file in tree by name and path
    {
        // Node* existingFile = findNode(name);
        // if (existingFile != NULL && existingFile->type == "file") 
        // {
        //     cout << "A file with the same name already exists" << endl;
        //     return;
        // }
        // Find the parent node
        Node* parentNode = findParentNode(path);
        if (parentNode == NULL) 
        {
            cout << "\e[1;41mInvalid path:\e[0;34m " << path << "\e[0m" << endl;
            return;
        }
        if (parentNode->name == "/")
        {
            cout << "\e[1;41mInvalid path:\e[0;34m " << path << "\e[0m" << endl;
            return;
        }
        if (parentNode->rightChild != NULL) 
        {
            cout << "\e[1;41mFile already exists: \e[0;34m" << path << "/" << name << "\e[0m" << endl;
            return;
        }
        parentNode->rightChild = new Node(name, path + "/" + name, "file");
        cout << "\e[1;32mFile created successfully.\e[0m" << endl;
    }

    void deleteFolder(string folderPath, string mergePath = "")
    {
        Node* folderNode = findNode(folderPath);
        if (folderNode == NULL) 
        {
            cout << "\e[1;41mFolder not found\e[0m" << endl;
            return;
        }
        if (folderNode->rightChild != NULL && mergePath.empty() == true)  // if folder is not empty then ask for confirmation to delete
        {
            cout << "\e[0;35mFolder is not empty, mention a file name to merge\e[0m" << endl;
            return;
        }
        if (folderNode->leftChild != NULL || folderNode->rightChild != NULL) 
        {
            if (!mergePath.empty()) 
            {
                Node* mergeFolder = findNode(mergePath);
                if (mergeFolder == NULL)
                {
                    if (mergeFolder == 0)
                    {
                        cout << "\e[0;35mFolder is not empty, mention a file name to merge\e[0m" << endl;
                        return;
                    }
                    cout << "\e[1;41mMerge folder not found\e[0m" << endl;
                    return;
                }
                if (mergeFolder->rightChild != NULL)  // if merge folder is not empty then ask for confirmation to merge
                {
                    cout << "\e[0;35mMerge folder is not empty. if you continue, your file in \e[0;33m" << mergeFolder->name << "\e[0;35m will be replaced by the \e[0;33m" << folderNode->name << "\e[0;35m file!\e[0m" << endl;
                    cout << "\e[0;34mDo you still want to merge?(yes/no): \e[0;33m";
                    string choice;
                    cin >> choice;
                    cout << "\e[0m";
                    if (choice == "no") 
                    {
                        return;
                    }
                    else
                    {
                        mergeFolder->rightChild = folderNode->rightChild;
                        Node* parentNodeS = findParent(folderNode);
                        parentNodeS->leftChild = folderNode->leftChild;
                        folderNode->leftChild = NULL;
                        folderNode->rightChild = NULL;
                        delete folderNode;
                        return;
                    }
                }
                mergeFolder->rightChild = folderNode->rightChild;
                Node* parentNodeS = findParent(folderNode);
                cout << parentNodeS->name << endl;
                parentNodeS->leftChild = folderNode->leftChild;
                folderNode->leftChild = NULL;
                folderNode->rightChild = NULL;
                delete folderNode;
                return;
                // mergeFolder->leftChild = folderNode->leftChild;
                // mergeFolder->rightChild = folderNode->rightChild;
            }
        }
        // Delete folderNode
        Node* parentNode = findParent(folderNode);
        cout << "Parent node: " << parentNode->name << endl;
        parentNode->leftChild = folderNode->leftChild;
        delete folderNode;
    }

    void copyFile(string fileName, string destDirPath)  // copy file from one directory to another
    {
        Node* fileNode = findNode(fileName);
        if (fileNode == NULL || fileNode->type != "file") 
        {
            cout << "File not found" << endl;
            return;
        }
        Node* destDirNode = findNode(destDirPath);
        if (destDirNode == NULL || destDirNode->type != "directory") 
        {
            cout << "\e[1;41mDestination directory not found\e[0m" << endl;
            return;
        }
        if (destDirNode->rightChild != NULL) 
        {
            cout << "\e[1;41mNot enough space in destination directory\e[0m" << endl;
            return;
        }
        createFile(fileNode->name, destDirNode->path);
        cout << "\e[0;32mFile copied successfully.\e[0m" << endl;
    }

    void moveFile(string fileName, string destDirPath) // move file from one directory to another
    {
        // copyFile(fileName, destDirPath);
        //deleteFile(fileName);
        Node* fileNode = findNode(fileName);
        Node* destDirNode = findNode(destDirPath);
        if (fileNode == NULL || fileNode->type != "file") 
        {
            cout << "File not found" << endl;
            return;
        }
        if (destDirNode == NULL || destDirNode->type != "directory") 
        {
            cout << "\e[1;41mDestination directory not found\e[0m" << endl;
            return;
        }
        if (destDirNode->rightChild != NULL) 
        {
            cout << "\e[1;41mNot enough space in destination directory\e[0m" << endl;
            return;
        }
        destDirNode->rightChild = fileNode;
        Node* srcDirNode = findFileParent(fileName, root);
        srcDirNode->rightChild = NULL;
        if (srcDirNode->leftChild == NULL && srcDirNode->rightChild == NULL) 
        {
            char response;
            cout << "\e[0;35mSource directory is empty. Do you want to delete it? (y/n): \e[0;33m";
            cin >> response;
            cout << "\e[0m";
            if (response == 'y' || response == 'Y') 
            {
                deleteFolder(srcDirNode->name, srcDirNode->path);
            }
        }
        cout << "\e[0;32mFile moved successfully.\e[0m" << endl;
    }

   Node* findFileParent(string name, Node* node, Node* parent = NULL)  // find parent of file node by name and node
   {
        if (node == NULL) 
        {
            return NULL;
        }

        if (node->name == name && node->type == "file") 
        {
            return parent;
        }

        Node* leftSearch = findFileParent(name, node->leftChild, node);
        if (leftSearch != NULL) 
        {
            return leftSearch;
        }

        return findFileParent(name, node->rightChild, node);
    }

    void deleteFile(string name, string path)  // delete file from tree by name and path
    {
        if (path.empty()) 
        {
            cout << "\e[1;41mPath not mentioned\e[0m" << endl;
            return;
        }
        Node* parentNode = findParentNode(path);
        Node* nodeToDelete = findNode(name);
        if (parentNode->rightChild != nodeToDelete) 
        {
            cout << "\e[1;41mInvalid file name: \e[0;34m" << name << "\e[0m" << endl;
            return;
        }
        if (parentNode == NULL) 
        {
            cout << "\e[1;41mNode is root or parent not found: \e[0;34m" << name << "\e[0m" << endl;
            return;
        }
        parentNode->rightChild = NULL;
        delete nodeToDelete;
        cout << "\e[0;32mFile deleted successfully.\e[0m" << endl;
    }

    void listDirectoryTree()  // list tree in level order traversal
    {
        if (root == NULL) {
            cout << "\e[1;41mThe directory tree is empty.\e[0m" << endl;
            return;
        }

        Queue queue;
        queue.enqueue(root);

        while (!queue.isEmpty()) 
        {
            Node* currentNode = queue.getFront();
            queue.dequeue();

            cout << currentNode->name << " ";

            if (currentNode->leftChild != NULL) 
            {
                queue.enqueue(currentNode->leftChild);
            }

            if (currentNode->rightChild != NULL) 
            {
                queue.enqueue(currentNode->rightChild);
            }
        }

        cout << endl;
    }

    void searchFile(string name, Node* node, string path) // search file in tree and print path
    {
        if (node == NULL) {
            return;
        }

        string temp = path + "/" + node->name;

        if (node->name == name && node->type == "file") 
        {
            temp.erase(0, 2);
            cout << "\e[0;35mFile path: \e[0m" << temp << endl;
        }

        searchFile(name, node->leftChild, path + "/" + node->name);
        searchFile(name, node->rightChild, path + "/" + node->name);
    }

    void searchFile(string name, string path) 
    {
        Node* temp = findNode(name);
        if (temp == NULL) 
        {
            cout << "\e[1;41mError: File/Folder not found\e[0m" << endl;
            return;
        }
        if (temp->type == "file")
        {
            searchFile(name, root, "");
        }
        if (temp->type == "directory")
        {
            if (temp->name == name)
            {
                cout << "True" << endl;
            }
        }
    }
    
    void mergeDirectories(string sourceName, string destinationName) 
    {
        Node* sourceNode = findNode(sourceName);
        Node* destinationNode = findNode(destinationName);

        if (sourceNode == NULL || destinationNode == NULL) 
        {
            cout << "\e[1;41mInvalid directory name.\e[0m" << endl;
            return;
        }

        // Move all children from source to destination
        // if (sourceNode->leftChild != NULL) 
        // {
        //     Node* currentNode = destinationNode;
        //     while (currentNode->rightChild != NULL) 
        //     {
        //         currentNode = currentNode->rightChild;
        //     }
        //     currentNode->rightChild = sourceNode->leftChild;
        // }

        if (sourceNode->rightChild != NULL) 
        {
            Node* currentNode = destinationNode;
            while (currentNode->rightChild != NULL) 
            {
                currentNode = currentNode->rightChild;
            }
            currentNode->rightChild = sourceNode->rightChild;
        }

        // Nullify the children of sourceNode before deleting it
        Node* parentNodeS = findParent(sourceNode);
        parentNodeS->leftChild = sourceNode->leftChild;
        sourceNode->leftChild = NULL;
        sourceNode->rightChild = NULL;
        delete sourceNode;

        string newName;
        cout << "\e[0;34mDo you want to keep the old name of the destination directory? (yes/no): \e[0;33m";
        cin >> newName;
        cout << "\e[0m";
        if (newName == "no") 
        {
            cout << "\e[0;32mEnter new name for the destination directory: \e[0;33m	";
            cin >> newName;
            cout << "\e[0m";
            destinationNode->name = newName;
        }
        cout << "\e[0;32mDirectories merged successfully.\e[0m" << endl;
    }

    Node* findNodeHelper(Node* node, string name) // find node
    {
        if (node == NULL) 
        {
            return NULL;
        }
        if (node->name == name) 
        {
            return node;
        }
        Node* foundNode = findNodeHelper(node->leftChild, name);
        if (foundNode != NULL) 
        {
            return foundNode;
        }
        return findNodeHelper(node->rightChild, name);
    }

    Node* findNode(string name)
    {
        return findNodeHelper(root, name);
    }

    // void deleteNode(string name)   // delete node OLD
    // {
    //     Node* nodeToDelete = findNode(name);
    //     if (nodeToDelete == NULL) 
    //     {
    //         cout << "Invalid node name: " << name << endl;
    //         return;
    //     }

    //     Node* parentNode = findParentNode(name);
    //     if (parentNode == NULL) 
    //     {
    //         cout << "Node is root or parent not found: " << name << endl;
    //         return;
    //     }

    //     if (parentNode->leftChild == nodeToDelete) 
    //     {
    //         parentNode->leftChild = NULL;
    //     } 
    //     else if (parentNode->rightChild == nodeToDelete) 
    //     {
    //         parentNode->rightChild = NULL;
    //     }

    //     delete nodeToDelete;
    // }

    void deleteNode(Node* nodeToDelete)  // delete node
    {
        if (nodeToDelete == NULL) 
        {
            cout << "\e[1;41mInvalid node name\e[0m" << endl;
            return;
        }
        Node* parentNode = findParentNode(nodeToDelete->name);
        if (parentNode == NULL) 
        {
            cout << "\e[1;41mNode is root or parent not found: \e[0;34m" << nodeToDelete->name << "\e[0m" << endl;
            return;
        }
        if (parentNode->leftChild == nodeToDelete) 
        {
            parentNode->leftChild = NULL;
        } 
        else if (parentNode->rightChild == nodeToDelete) 
        {
            parentNode->rightChild = NULL;
        }

        delete nodeToDelete;
    }

    Node* findParent(Node* nodeToFind) // find parent node but with node type
    {
        Node* leftcheck = root->leftChild;
        Node* rightcheck = root->rightChild;
        bool flag1 = false;
        bool flag2 = false;
        while(leftcheck->leftChild != nullptr)
        {
            if (leftcheck->leftChild == nodeToFind)
            {
                flag1 = true;
                break;
            }
            leftcheck = leftcheck->leftChild;
        }
        while(rightcheck->leftChild != nullptr)
        {
            if (rightcheck->leftChild == nodeToFind)
            {
                flag2 = true;
                break;
            }
            rightcheck = rightcheck->leftChild;
        }
        if (flag1 == true)
        {
            return leftcheck;
        }
        else if (flag2 == true)
        {
            return rightcheck;
        }
        else
        {
            return NULL;
        }
    }

    Node* findParentNode(string path) // find parent node
    {
        Node* currentNode = root;
        stringstream ss(path);
        string directory;

        // Skip the root directory ('/')
        getline(ss, directory, '/');

        while (getline(ss, directory, '/'))
        {
            if (currentNode->leftChild != NULL && currentNode->leftChild->name == directory) 
            {
                currentNode = currentNode->leftChild;
            } 
            else if (currentNode->rightChild != NULL && currentNode->rightChild->name == directory) 
            {
                currentNode = currentNode->rightChild;
            } 
            else 
            {
                return NULL;
            }
        }
        return currentNode;
    }

    void printTree(Node* node, int depth) // print tree
    {
        if (node == NULL) 
        {
            return;
        }

        for (int i = 0; i < depth; i++) 
        {
            cout << " ";
        }
        if (node->type == "file")
        {
            Node* parentNode = findFileParent(node->name, root);
            cout << node->name << "\e[0;35m (" << parentNode->name << ")\e[0m" << endl;
        }
        else
        {
            cout << node->name << endl;
        }

        if (node->leftChild != NULL) 
        {
            if (node->leftChild->type == "directoryM")
            {
                printTree(node->leftChild, 2);
            }
            if (node->leftChild->type == "directory")
            {
                printTree(node->leftChild, 4);
            }
            if (node->leftChild->type == "file")
            {
                printTree(node->leftChild, 6);
            }
        }

        if (node->rightChild != NULL) 
        {
            if (node->rightChild->type == "directoryM")
            {
                printTree(node->rightChild, 2);
            }
            if (node->rightChild->type == "directory")
            {
                printTree(node->rightChild, 4);
            }
            if (node->rightChild->type == "file")
            {
                printTree(node->rightChild, 6);
            }
        }
    }

    void printTree() 
    {
        printTree(root, 0);
    }

    void printLeftRightNodes(string node) // print left and right nodes of a node
    {
        Node* check = findNode(node);
        if (check->leftChild == NULL && check->rightChild == NULL)
        {
            cout << "\e[0;34mNo children\e[0m" << endl;
            return;
        }
        if (check->leftChild == NULL && check->rightChild != NULL)
        {
            cout << "\e[0;35mLeft child:\e[0;34m No child\e[0m" << endl;
            cout << "\e[0;35mRight child: \e[0;32m" << check->rightChild->name << "\e[0m" << endl;
        }
        if (check->leftChild != NULL && check->rightChild == NULL)
        {
            cout << "\e[0;35mLeft child: \e[0;32m" << check->leftChild->name << "\e[0m" << endl;
            cout << "\e[0;35mRight child:\e[0;34m No child" << endl;
        }
        if (check->leftChild != NULL && check->rightChild != NULL)
        {
            cout << "\e[0;35mLeft child: \e[0;32m" << check->leftChild->name << "\e[0m" << endl;
            cout << "\e[0;35mRight child: \e[0;32m" << check->rightChild->name << "\e[0m" << endl;
        }
    }

    string removeFileName(const std::string& fullPath) 
    {
        size_t lastSlashPos = fullPath.find_last_of('/');
        if (lastSlashPos == std::string::npos) 
        {
            return fullPath;
        } 
        else 
        {
            return fullPath.substr(0, lastSlashPos);
        }
    }
    
    void exportDirectories(Node* node, ofstream& file) 
    {
        if (node == NULL) 
        {
            return;
        }

        // If the node is a directory, write its name and path to the file
        if (node->type == "directory") 
        {
            string path = removeFileName(node->path);
            file << node->name << " " << path << "\n";
        }
        if (node->type == "file") 
        {
            string path = removeFileName(node->path);
            file << node->name << " " << path << "\n";
        }

        // Recursively export the directories in the left and right subtrees
        exportDirectories(node->leftChild, file);
        exportDirectories(node->rightChild, file);
    }

    void exportTreeDirectories(Node* node, const string& filename)  // export tree to file
    {
        ofstream file;
        file.open(filename);
        if (!file) {
            cout << "Unable to open file for writing.\n";
            return;
        }

        exportDirectories(node, file);

        file.close();
    }

    void importTreeFromFile(Node* node, ifstream& file) {
        string name, path;

        while (file >> name >> path) 
        {
            if (name.find('.') != string::npos) 
            {  // If the name contains a '.', it's a file
                createFile(name, path);
            } 
            else 
            {  // Otherwise, it's a directory
                createDirectory(name, path);
            }
        }
    }

    // these functions are to call for import and export
    void exportT(string name)
    {
        exportTreeDirectories(root, name);
        cout << "\e[0;32mTree exported successfully.\e[0m" << endl;
    }
    void importT(string name)
    {
        ifstream file;
        file.open(name);
        importTreeFromFile(root, file);
        cout << "\e[0;32mTree imported successfully.\e[0m" << endl;
    }
};