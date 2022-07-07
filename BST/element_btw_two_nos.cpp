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

void print_btw(bTreeNode<int>* root, int k1, int k2) {
    if (root == NULL) {
        return;
    }

    if (root->data < k1) {
        print_btw(root->right, k1, k2);
    } else if(root->data > k2) {
        print_btw(root->left, k1, k2);
    } else if (root->data >= k1 && root->data <= k2) {
        print_btw(root->left, k1, k2);
        cout << root->data << " ";
        print_btw(root->right, k1, k2);
    }
    return;
}

int main() {
    bTreeNode<int>* root = getInput();
    int k1, k2;
    cin >> k1;
    cin >> k2;

    print_btw(root, k1, k2);
}