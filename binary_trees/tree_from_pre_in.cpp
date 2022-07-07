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

bTreeNode<int>* constructor(int pre[], int in[], int pre_s, int pre_e, int in_s, int in_e) {
    if (pre_s == pre_e && in_s == in_e) {

        bTreeNode<int>* n = new bTreeNode(pre[pre_s]);

        return n;

    }

    bTreeNode<int>* root = new bTreeNode(pre[pre_s]);

    int i = in_s;
    while (in[i] != root->data) {
        i++;
    }


    int initial_pre_e = pre_e;
    int initial_in_e = in_e;
    pre_s++;
    pre_e = pre_s + (i-1 - in_s);
    in_e = i-1;

    if (pre_s <= pre_e &&in_s <= in_e) {
        bTreeNode<int>* left_node = constructor(pre, in, pre_s, pre_e , in_s, in_e);
        root->left = left_node;
    }


    pre_s = pre_e+1;
    pre_e = initial_pre_e;
    in_s = i+1;
    in_e = initial_in_e;

    if (pre_s <= initial_pre_e && in_s <= initial_in_e){
        bTreeNode<int>* right_node = constructor(pre, in, pre_s, pre_e, in_s, in_e);
        root->right = right_node;
    }

    return root;

}

void printLW(bTreeNode<int>* root) {
    queue<bTreeNode<int>*> pending;
    pending.push(root);

    while (!pending.empty()) {
        bTreeNode<int>* front = pending.front();
        pending.pop();

        if (front->left != NULL) {
            pending.push(front->left);
        }
        if (front->right != NULL) {
            pending.push(front->right);
        }


        cout << front->data << ": ";
        if (front->left != NULL) {
            cout << "L" << front->left->data << " ";
        }
        if (front->right != NULL) {
            cout << "R" << front->right->data;
        }
        cout << endl;
    }
}


int main() {
    int n;
    cin >> n;

    int* pre = new int[n];
    int* in = new int[n];    

    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    bTreeNode<int>* tree = constructor(pre, in, 0, n-1, 0, n-1);
    printLW(tree);
}

