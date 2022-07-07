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


vector<int>* findPath(bTreeNode<int>* root, int num) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == num) {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    } else if (root->data < num) {
        vector<int>* rightOutput = findPath(root->right, num);
        if (rightOutput != NULL) {
            rightOutput->push_back(root->data);
            return rightOutput;
        }
    } else {
        vector<int>* leftOutput = findPath(root->left, num);
        if (leftOutput != NULL) {
            leftOutput->push_back(root->data);
            return leftOutput;
        }
    }
    return NULL;
}



int main() {
    bTreeNode<int>* root = getInput();
    int n;
    cin >> n;

    vector<int>* ans = findPath(root, n);
    for (int i = 0 ; i < ans->size(); i++) {
        cout << ans->at(i) << " ";
    }
}