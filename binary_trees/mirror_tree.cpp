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

void mirror_tree(bTreeNode<int>* root) {
    queue<bTreeNode<int>*> pending;
    pending.push(root);

    bTreeNode<int>* null_node = new bTreeNode(-1);
    pending.push(null_node);

    while (!pending.empty()){
        bTreeNode<int>* front = pending.front();
        pending.pop();

        if (front->data == -1) {
            if (pending.size() == 0) {
                break;
            }
            cout << endl;
            pending.push(null_node);
        } else {
            if (front->right != NULL) {
                pending.push(front->right);
            }
            if (front->left != NULL) {
                pending.push(front->left);
            }

            cout << front->data << " ";
        }
    }
}


int main() {
    bTreeNode<int>* root = getInput();
    mirror_tree(root);
}