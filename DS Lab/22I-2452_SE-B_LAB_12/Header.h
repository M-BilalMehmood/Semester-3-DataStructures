#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Node 
{
    string word;
    int count;
    int height;
    Node* left;
    Node* right;
};

class AVLTree 
{
    private:
        Node* root;

        int height(Node* N) 
        {
            if (N == NULL)
                return 0;
            return N->height;
        }

        Node* newNode(string word)
        {
            Node* node = new Node();
            node->word = word;
            node->left = NULL;
            node->right = NULL;
            node->count = 1;
            node->height = 1;
            return(node);
        }

        Node* rightRotate(Node* y) 
        {
            Node* x = y->left;
            Node* T2 = x->right;
            x->right = y;
            y->left = T2;
            y->height = max(height(y->left), height(y->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;
            return x;
        }

        Node* leftRotate(Node* x) 
        {
            Node* y = x->right;
            Node* T2 = y->left;
            y->left = x;
            x->right = T2;
            x->height = max(height(x->left), height(x->right)) + 1;
            y->height = max(height(y->left), height(y->right)) + 1;
            return y;
        }

        int getBalance(Node* N) 
        {
            if (N == NULL)
                return 0;
            return height(N->left) - height(N->right);
        }

        Node* insert(Node* node, string word) 
        {
            if (node == NULL)
                return(newNode(word));
            if (word < node->word)
            {
                node->left = insert(node->left, word);
            }
            else if (word > node->word)
            {
                node->right = insert(node->right, word);
            }
            else 
            {
                node->count++;
                return node;
            }
            node->height = 1 + max(height(node->left), height(node->right));
            int balance = getBalance(node);
            if (balance > 1 && word < node->left->word)
            {
                return rightRotate(node);
            }
            if (balance < -1 && word > node->right->word)
            {
                return leftRotate(node);
            }
            if (balance > 1 && word > node->left->word) 
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            if (balance < -1 && word < node->right->word) 
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            return node;
        }

        void preOrder(Node* root, string prefix) 
        {
            if(root != NULL) 
            {
                if(root->word.find(prefix) == 0)
                {
                    cout << "\e[0;32m" << root->word << " \e[0;35m(Occurence: " << root->count << ")\e[0m" << endl;
                }
                preOrder(root->left, prefix);
                preOrder(root->right, prefix);
            }
        }

        Node* minValueNode(Node* node) 
        {
            Node* current = node;
            while (current->left != NULL)
            {
                current = current->left;
            }
            return current;
        }

        Node* deleteNode(Node* root, string word) 
        {
            if (root == NULL)
                return root;
            if (word < root->word)
            {
                root->left = deleteNode(root->left, word);
            }
            else if(word > root->word)
            {
                root->right = deleteNode(root->right, word);
            }
            else 
            {
                if(root->count > 1) 
                {
                    root->count--;
                    return root;
                }
                else if((root->left == NULL) || (root->right == NULL)) 
                {
                    Node *temp = root->left ? root->left : root->right;
                    if(temp == NULL) 
                    {
                        temp = root;
                        root = NULL;
                    } 
                    else
                        *root = *temp;
                    free(temp);
                } 
                else 
                {
                    Node* temp = minValueNode(root->right);
                    root->word = temp->word;
                    root->right = deleteNode(root->right, temp->word);
                }
            }
            if (root == NULL)
                return root;
            root->height = 1 + max(height(root->left), height(root->right));
            int balance = getBalance(root);
            if (balance > 1 && getBalance(root->left) >= 0)
            {    
                return rightRotate(root);
            }
            if (balance > 1 && getBalance(root->left) < 0) 
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && getBalance(root->right) <= 0)
            {
                return leftRotate(root);
            }
            if (balance < -1 && getBalance(root->right) > 0) 
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
        }

    public:
        AVLTree() : root(nullptr) {};

        void insert(string word) 
        {
            root = insert(root, word);
        }

        void autocomplete(string prefix) 
        {
            preOrder(root, prefix);
        }
        
        void deleteWord(string word) 
        {
            root = deleteNode(root, word);
        }
        
         void loadDictionary(string filename) 
         {
            ifstream file(filename);
            string word;
            while (file >> word) 
            {
                insert(word);
            }
        }

        Node* print(Node* root) 
        {
            if(root != NULL) 
            {
                print(root->left);
                cout << "\e[0;32m" << root->word << " \e[0;35m(Occurence: " << root->count << ")\e[0m" << endl;
                print(root->right);
            }
            return root;
        }

        void print() 
        {
            print(root);
        }
};