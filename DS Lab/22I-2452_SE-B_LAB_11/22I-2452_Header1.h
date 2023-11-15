#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node() : data(0), left(nullptr), right(nullptr) {};
    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

class Tree
{
private:
    Node* root;
    Node* insertBST(Node* node, int val)
    {
        if(node == nullptr)
        {
            return new Node(val);
        }
        if (val > node->data)
        {
            node->right = insertBST(node->right, val);
        }
        if (val < node->data)
        {
            node->left = insertBST(node->left, val);
        }
    }
    Node* deleteBST(Node* node, int key)
    {
        if(node == nullptr)
        {
            return node;
        }
        if (key < node->data)
        {
            node->left = deleteBST(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = deleteBST(node->right, key);
        }
        else
        {
            if(node->left = nullptr)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if (node->right == nullptr)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(node->right);
        }
    }
    Node* minValueNode(Node* node)
    {
        Node* current = node;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
};