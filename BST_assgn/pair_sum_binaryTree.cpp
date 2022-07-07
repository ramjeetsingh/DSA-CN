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

void preorder(bTreeNode<int>* root, vector<int> &pre) {
    if (root == NULL) {
        return;
    }

    pre.push_back(root->data);

    preorder(root->left, pre);
    preorder(root->right, pre);
    return;

}


int main() {
    bTreeNode<int>* root = getInput();

    int n;
    cin >> n;

    vector<int> arr;
    preorder(root, arr);

    sort(arr.begin(), arr.end());

    int i = 0, j = arr.size()-1;

    while (i < j) {
        if (arr[i] + arr[j] == n) {
            cout << arr[i] << " " << arr[j] << endl;
            i++;
            j--;
        } else if (arr[i] + arr[j] < n) {
            i++;
        } else {
            j--;
        }
    }
}