#include <iostream>
#include <queue>
using namespace std;


template <typename T>
class bTreeNode {
    public:
    T data;
    bTreeNode<T>* left;
    bTreeNode<T>* right;

    bTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~bTreeNode() {
        delete left;
        delete right;
    }
};


bTreeNode<int>* getInput() {
    int rootData;
    cin >> rootData;

    if (rootData == -1) {
        return NULL;
    }

    bTreeNode<int>* root = new bTreeNode<int>(rootData);
    queue<bTreeNode<int>*> pending;

    pending.push(root);

    while (!pending.empty()) {
        bTreeNode<int>* front = pending.front();
        pending.pop();

        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            bTreeNode<int>* leftNode = new bTreeNode<int>(leftData);
            front->left = leftNode;
            pending.push(leftNode);
        }

        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            bTreeNode<int>* rightNode = new bTreeNode<int>(rightData);
            front->right = rightNode;
            pending.push(rightNode);
        }
    }
    return root;
}


class BST {
    bTreeNode<int>* root;

    bool hasDataHelp(int data, bTreeNode<int>* node) {
        if (node == NULL) {
            return false;
        }

        if (node->data == data) {
            return true;
        } else if (node->data < data) {
            return hasDataHelp(data, root->right);
        } else {
            return hasDataHelp(data, root->left);
        }
    }


    bTreeNode<int>* insertHelp(int data, bTreeNode<int>* node) {
        if (node == NULL) {
            bTreeNode<int>* newNode = new bTreeNode(data);
            return newNode;
        }

        if (node->data < data) {
            bTreeNode<int>* rightNode = insertHelp(data, node->right);
            node->right = rightNode;
        } else {
            bTreeNode<int>* leftNode = insertHelp(data, node->left);
            node->left = leftNode;
        }
        return node;
    }


    bTreeNode<int>* deleteHelp(int data, bTreeNode<int>* node) {
        if (node == NULL) {
            return NULL;
        }

        if (node->data < data) {
            node->right = deleteHelp(data, node->right);
            return node;
    
        } else if (node->data > data) {
            node->left = deleteHelp(data, node->left);
            return node; 
            
        } else {

            if (node->left == NULL && node->right==NULL) {
                delete node;
                return NULL;

            } else if (node->left == NULL) {
                bTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;

            } else if (node->right == NULL) {
                bTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;

            } else {
                bTreeNode<int>* minNode = node->right;
                while (minNode->left != NULL) {
                    minNode = minNode->left;
                }

                int minData = minNode->data;
                node->data = minData;
                node->right = deleteHelp(minData, node->right);
                return node;
            }
        }
    }

    void printHelp(bTreeNode<int>* root) {
        if (root == NULL) {
            return;
        }

        cout << root->data << ": ";

        if (root->left != NULL) {
            cout << "L" << root->left->data;
        }
        if (root->right != NULL) {
            cout << "R" << root->right->data;
        }
        cout << endl;

        printHelp(root->left);
        printHelp(root->right);
    }


    public:

    BST() {
        root = NULL;
    }

    ~BST() {
        delete root;
    }

    bool hasData(int data) {
        return hasDataHelp(data, root);
    }

    void insert(int data) {
        this->root = insertHelp(data, this->root);
    }

    void deleteData(int data) {
        this->root = deleteHelp(data, root);
    }

    void print() {
        printHelp(root);
    }
};


int main() {
    BST b;
    b.insert(4);
    b.insert(1);
    b.insert(10);
    b.insert(2);
    b.insert(7);
    b.insert(8);

    b.deleteData(10);
    b.print();
}