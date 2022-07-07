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


bTreeNode<int>* construct(int arr[], int start, int end) {
    if (start >= end) {
        bTreeNode<int>* leaf = new bTreeNode(arr[start]);
        cout << leaf->data << " ";
        return leaf;
    }

    int mid = (start + end)/2;
    bTreeNode<int>* root = new bTreeNode(arr[mid]);
    cout << root->data << " ";

    bTreeNode<int>* leftSubtree = construct(arr, start, mid-1);
    bTreeNode<int>* rightSubtree = construct(arr, mid+1, end);

    root->left = leftSubtree;
    root->right = rightSubtree;
    return root;
}


int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bTreeNode<int>* root = construct(arr, 0, n-1);
}