#include <iostream>
#include <queue>
#include <string>
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


void print_path(bTreeNode<int>* root, int remaining_sum, string path) {
    if (root == NULL) {
        return;
    }

    if (remaining_sum < 0) {
        return;
    }

    path.append(to_string(root->data) + " ");
    remaining_sum -= root->data;

    if (root->left == NULL && root->right == NULL) {
        if (remaining_sum == 0) {
            cout << path << endl;
        }
        return;
    }

    print_path(root->left, remaining_sum, path);
    print_path(root->right, remaining_sum, path);
    return;
}



int main() {
    bTreeNode<int>* root = getInput();
    int k;
    cin >> k;

    string ans = "";

    print_path(root, k, ans);
}