#include<iostream>
using namespace std;

class Node //Node class with a new member height
{
public:
    int data;
    int height;
    Node *left, *right;
    Node() : data(0), height(0), left(nullptr), right(nullptr) {};
    Node(int val) : data(val), left(nullptr), right(nullptr) {};
    int setHeight(int h) { height = h; }
};

class Tree
{
private:
    Node* root;
    Node* insertBST(Node* node, int val)
    {
        if (node == NULL)
        {
            node = new Node(val);
        }
        if (val < node->data)
        {
            node->left = insertBST(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insertBST(node->right, val);
        }
        return balance(node);
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
            node->data = temp->data;
            node->right = deleteBST(node->right, temp->data);
        }
        return balance(node);
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
    int updateHeight(Node* node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        int leftHeight = (node->left != nullptr)? updateHeight(node->left) : 0;
        int rightHeight = (node->right != nullptr)? updateHeight(node->right) : 0;
        return max(leftHeight, rightHeight) + 1;
    }
    Node* LL(Node* node) 
    {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        node->height = updateHeight(node);
        newRoot->height = updateHeight(newRoot);
        return newRoot;
    }
    Node* RR(Node* node) 
    {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        node->height = updateHeight(node);
        newRoot->height = updateHeight(newRoot);
        return newRoot;
    }
    Node* LR(Node* node) 
    {
        node->left = RR(node->left);
        return LL(node);
    }
    Node* RL(Node* node) 
    {
        node->right = LL(node->right);
        return RR(node);
    }
    int getBalanceFactor(Node* node) 
    {
        if (node == nullptr) 
        {
            return 0;
        }
        return (updateHeight(node->left) - 1) - (updateHeight(node->right) - 1);
    }
    Node* balance(Node* node) 
    {
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) 
        {
            if (getBalanceFactor(node->left) >= 0) 
            {
                return LL(node);
            } 
            else 
            {
                return LR(node);
            }
        } 
        else if (balanceFactor < -1) 
        {
            if (getBalanceFactor(node->right) <= 0) 
            {
                return RR(node);
            } 
            else 
            {
                return RL(node);
            }
        }
        node->height = updateHeight(node);
        return node;
    }
    void printTree(Node* node, string indent = "") 
    {
        if (node == nullptr)
        {
            return;
        }
        printTree(node->right, indent + "   ");
        cout << indent << node->data << "\n";
        printTree(node->left, indent + "   ");
    }
public://getters and setters to access the private functions
    Tree() : root(0) {};
    void insert(int val)
    {
        root = insertBST(root, val);
        balance(root);
    }
    void deleting(int val)
    {
        root = deleteBST(root, val);
    }
    void print()
    {
        printTree(root);
    }
};