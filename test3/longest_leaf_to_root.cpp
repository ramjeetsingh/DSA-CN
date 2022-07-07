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

void find_height(bTreeNode<int>* root, int ht_of_this_path, int &max_ht_till_now) {
    if (root == NULL) {
        if (ht_of_this_path > max_ht_till_now) {
            max_ht_till_now = ht_of_this_path;
        }
        return;
    }

    find_height(root->left, 1+ht_of_this_path, max_ht_till_now);
    find_height(root->right, 1+ht_of_this_path, max_ht_till_now);
    return;
}


void find_path(bTreeNode<int>* root, int remaining_height, string path, bool &printed) {
    if (root == NULL) {
        if (remaining_height == 0 && !printed) {
            cout << path << endl;
            printed = true;
        }
        return;
    }

    path.append((to_string(root->data) + " "));
    remaining_height--;

    find_path(root->left, remaining_height, path, printed);
    find_path(root->right, remaining_height, path, printed);
    return;
}



int main() {
    bTreeNode<int>* root = getInput();
    int height = 0;
    find_height(root, 0, height);

    string ans = "";
    bool printed = false;
    find_path(root, height, ans, printed);
}