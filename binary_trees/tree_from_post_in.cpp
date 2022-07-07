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

bTreeNode<int>* constructor(int post[], int in[], int post_s, int post_e, int in_s, int in_e) {
    if (post_s == post_e && in_s == in_e) {
        bTreeNode<int>* leaf = new bTreeNode(post[post_s]);
        return leaf;
    }

    bTreeNode<int>* root = new bTreeNode(post[post_e]);

    int i = 0;
    for (int j = in_s; j <= in_e; j++) {
        if (in[j] == root->data) {
            break;
        }
        i++;
    }
        
    int initial_post_e = post_e;
    int initial_in_e = in_e;

    post_e = i-1 + post_s;
    in_e = i - 1 + in_s;
    if (post_s <= post_e && in_s <= in_e) {
        bTreeNode<int>* left_node = constructor(post, in, post_s, post_e, in_s, in_e);
        root->left = left_node;
    }
        

    post_s += i;
    post_e = initial_post_e-1;
    in_e = initial_in_e;
    in_s += (i+1);
    if (post_s <= post_e && in_s <= in_e) {
        bTreeNode<int>* right_node = constructor(post, in, post_s, post_e, in_s, in_e);
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

    int* post = new int[n];
    int* in = new int[n];    

    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    bTreeNode<int>* tree = constructor(post, in, 0, n-1, 0, n-1);
    printLW(tree);
}