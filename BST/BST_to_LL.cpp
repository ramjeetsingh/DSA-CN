#include <iostream>
#include <queue>
using namespace std;

class LLnode {
    public:
    int data;
    LLnode* next;

    LLnode(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Pair {
    public:
    LLnode* head;
    LLnode* tail;
};


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

Pair help(bTreeNode<int>* root) {
    if (root == NULL) {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    LLnode* root_node = new LLnode(root->data);

    Pair leftAns = help(root->left);
    Pair rightAns = help(root->right);

    Pair ans;

    if (!leftAns.head && !rightAns.head) {
        ans.head = root_node;
        ans.tail = root_node;
    } else if (leftAns.head && !rightAns.head) {
        leftAns.tail->next = root_node;
        ans.head = leftAns.head;
        ans.tail = root_node;
    } else if (!leftAns.head && rightAns.head) {
        root_node->next = rightAns.head;
        ans.head = root_node;
        ans.tail = rightAns.tail;
    } else {
        leftAns.tail->next = root_node;
        root_node->next = rightAns.head;
        ans.head = leftAns.head;
        ans.tail = rightAns.tail;
    }
    return ans;
}

LLnode* convert(bTreeNode<int>* root) {
    Pair ans = help(root);
    return ans.head;
}



int main() {
    bTreeNode<int>* root = getInput();

    LLnode* LLhead = convert(root);

    while (LLhead != NULL) {
        cout << LLhead->data << " ";
        LLhead = LLhead->next;
    }
}