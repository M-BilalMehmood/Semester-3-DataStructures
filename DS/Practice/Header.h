#include<iostream>
#include<string>
using namespace std;

class Tree
{
    struct Node
    {
        int data;
        Node *left, *right;
    }*root;
private:
    void inorder(Node* root)
    {
        if(!root) { return; }
        else
        {
            inorder (root->left);
            cout << root->data;
            inorder (root->right);
        }
    }
    void preorder(Node* root)
    {
        if(!root) { return; }
        else
        {
            cout << root->data;
            preorder (root->left);
            preorder (root->right);
        }
    }
    void postorder(Node* root)
    {
        if(!root) { return; }
        else
        {
            postorder (root->left);
            postorder (root->right);
            cout << root->data;
        }
    }

public:
    void display(int choice)
    {
        if (choice == 1)
        {
            preorder(this->root);
        }
        else if (choice == 2)
        {
            inorder(this->root);
        }
        else if (choice == 3)
        {
            postorder(this->root);
        }
        else
        {
            cout << "error" << endl;
        }
    }
    bool insert(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        if(!root)
        {
            root = newNode;
        }
        else
        {
            Node* temp = root;
            while(!temp)
            {
                if(temp->data == value)
                {
                    cout << "Duplicates not allowed!" << endl;
                    delete newNode;
                    return false;
                }
                else
                {
                    if(temp->data > value)
                    {
                        if(!temp->left) { temp->left = newNode; }
                        temp = temp->left;
                    }
                    else if(temp->data < value)
                    {
                        if(!temp->right) { temp->right = newNode; }
                        temp = temp->right;
                    }                    
                }
            }
        }
    }
};