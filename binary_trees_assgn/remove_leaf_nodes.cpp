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

void remove(bTreeNode<int>* &root) {
    if (root->left == NULL && root->right == NULL) {
        root = NULL;
        return;
    }

    bool left_removed = false;
    bool right_removed = false;

    if (root->left != NULL) {
        if (root->left->left == NULL && root->left->right == NULL) {
            root->left = NULL;
            left_removed = true;
        }
    } else {
        left_removed = true;
    }

    if (root->right != NULL) {
        if (root->right->left == NULL && root->right->right == NULL) {
            root->right = NULL;
            right_removed = true;
        }
    } else {
        right_removed = true;
    }
    
    

    if (!left_removed) {
        remove(root->left);
    }
    if (!right_removed) {
        remove(root->right);
    }
    return;
}


int main() {
    bTreeNode<int>* root = getInput();
    remove(root);
    levelOrder(root);
}