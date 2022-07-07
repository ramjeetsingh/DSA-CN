#include <iostream>
#include <queue>
#include <bits/stdc++.h>
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

bool search(int data, bTreeNode<int>* root) {
    if (root == NULL) {
        return false;
    }

    if (root->data == data) {
        return true;
    } else if (root->data < data) {
        return search(data, root->right);
    } else {
        return search(data, root->left);
    }
}

bTreeNode<int>* LCA_BST(bTreeNode<int>* root, int n, int m) {
    if (root == NULL) {
        return NULL;
    }

    bTreeNode<int>* ans = root;

    if (n < root->data && m < root->data) {
        ans = LCA_BST(root->left, n, m);
    } else if (n > root->data && m > root->data) {
        ans = LCA_BST(root->right, n, m);
    }

    return ans;
}



int main() {
    bTreeNode<int>* root = getInput();

    int n, m;
    cin >> n >> m;

    if (!search(n, root) && !search(m, root)) {
        cout << -1;
    } else if (!search(m, root)) {
        cout << n;
    } else if (!search(n, root)) {
        cout << m;
    } else {
        bTreeNode<int>* output = LCA_BST(root, n, m);
        cout << output->data;
    }
}