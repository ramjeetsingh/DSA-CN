#include <iostream>
#include <queue>
#include <cmath>
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


int replace(bTreeNode<int>* root, int sum) {
    if (root == NULL) {
        return 0;
    }

    int sum_of_rightSub = replace(root->right, sum);

    sum += sum_of_rightSub + root->data;

    int initial_root_data = root->data;
    root->data = sum;
    
    int sum_of_leftSub = replace(root->left, sum);
    
    return sum_of_rightSub+initial_root_data+sum_of_leftSub;
}

void levelOrder(bTreeNode<int>* root) {
    queue<bTreeNode<int>*> pending;
    pending.push(root);

    bTreeNode<int>* null_node = new bTreeNode(-1);
    pending.push(null_node);

    while (!pending.empty()) {
        bTreeNode<int>* front = pending.front();
        pending.pop();

        if (front->data == -1) {
            if (pending.empty()) {
                break;
            }
            cout << endl;
            pending.push(null_node);
        } else {
            if (front->left != NULL) {
                pending.push(front->left);
            }
            if (front->right != NULL) {
                pending.push(front->right);
            }

            cout << front->data <<" ";
        }
    }
}



int main() {
    bTreeNode<int>* root = getInput();
    int output = replace(root, 0);
    levelOrder(root);
}