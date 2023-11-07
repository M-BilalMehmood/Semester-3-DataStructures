#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};
// this is the change
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder(Node* node) {
    if (node == NULL)
        return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void preorder(Node* node) {
    if (node == NULL)
        return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->right->left = newNode(13);
    root->right->left->left = newNode(11);
    root->right->left->right = newNode(14);
    root->right->right = newNode(16);
    root->right->right->right = newNode(17);
    root->left->right = newNode(8);
    root->left->right->left = newNode(6);

    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << "\n";

    std::cout << "Preorder traversal: ";
    preorder(root);
    std::cout << "\n";

    std::cout << "Postorder traversal: ";
    postorder(root);
    std::cout << "\n";

    return 0;
}