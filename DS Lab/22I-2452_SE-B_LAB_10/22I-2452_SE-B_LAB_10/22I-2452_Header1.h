#pragma once
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left, * right;
    Node(int give) : data(give), left(NULL), right(NULL) {};
};

class Tree
{
private:
    Node* root;
    Node* insertBST(Node* node, int val)
    {
        if (node == NULL)
        {
            return new Node(val);
        }
        if (val < node->data)
        {
            node->left = insertBST(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insertBST(node->right, val);
        }
        return node;
    }
    Node* deleteBST(Node* root, int key)
    {
        if (root == NULL) { return root; }
        if (key < root->data) { root->left = deleteBST(root->left, key); }
        else if (key > root->data) { root->right = deleteBST(root->right, key); }
        else
        {
            if (root->left == NULL)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteBST(root->right, temp->data);
        }
        return root;
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
    int height(Node* node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int lHeight = height(node->left);
            int rHeight = height(node->right);
            if (lHeight > rHeight) { return(lHeight + 1); }
            else { return(rHeight + 1); }
        }
    }
    int findDepth(Node* node, int val, int depth = 1)
    {
        if (node == NULL) { return -1; }
        if (node->data == val) { return depth; }

        int downlevel = findDepth(node->left, val, depth + 1);
        if (downlevel != -1) { return downlevel; }

        downlevel = findDepth(node->right, val, depth + 1);
        return downlevel;
    }
    int countRange(Node* node, int L, int R)
    {
        if (node == NULL)
        {
            return 0;
        }
        if (node->data >= L && node->data <= R)
        {
            return 1 + countRange(node->left, L, R) + countRange(node->right, L, R);
        }
        else if (node->data < L)
        {
            return countRange(node->right, L, R);
        }
        else
        {
            return countRange(node->left, L, R);
        }
    }
    void kthSmallestUtil(Node* node, int& k, int& res)
    {
        if (node == NULL || k < 0)
            return;

        kthSmallestUtil(node->left, k, res);

        k--;
        if (k == 0)
        {
            res = node->data;
            return;
        }

        kthSmallestUtil(node->right, k, res);
    }
    void inorder(Node* node)
    {
        if (node == NULL) { return; }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
	}
public:
    Tree() : root(NULL) {};
    void insert(int val)
    {
        root = insertBST(root, val);
    }
    void deleteVal(int val)
    {
        root = deleteBST(root, val);
    }
    int getHeight()
    {
        return height(root);
    }
    int findDepth(int val)
    {
        return findDepth(root, val);
    }
    int countRange(int L, int R)
    {
        return countRange(root, L, R);
    }
    int GOkthSmallest(int k)
    {
        int res = -1;
        kthSmallestUtil(root, k, res);
        return res;
    }
    void inorder()
    {
		inorder(root);
	}
};