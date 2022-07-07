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


class Pair {
    public:

    int max;
    int min;

    Pair() {
        max = INT_MIN;
        min = INT_MAX;
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


void find(bTreeNode<int>* root, Pair &ans) {
    if (root == NULL) {
        return;
    }

    if (root->data > ans.max) {
        ans.max = root->data;
    }
    if (root->data < ans.min) {
        ans.min = root->data;
    }

    find(root->left, ans);
    find(root->right, ans);
    return;
}



int main() {
    bTreeNode<int>* root = getInput();
    Pair ans;

    find(root, ans);
    cout << ans.min << " " << ans.max;
}