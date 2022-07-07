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

int find_level(bTreeNode<int>* root, int data, int level) {
    if (root == NULL) {
        return 0;
    }
    if (root ->data == data) {
        return level;
    }

    int atLeft = find_level(root->left, data, level+1);
    if (atLeft != 0) {
        return atLeft;
    }

    return find_level(root->right, data, level+1);
}

bool siblings(bTreeNode<int>* root, int p, int q) {
    if (root == NULL) {
        return false;
    }

	if(root->left && root->right){
		if((root->left->data == p && root->right->data == q) ||
			(root->left->data == q && root->right->data == p)) return 1;
	}
	return (siblings(root->left,p, q) || siblings(root->right,p, q));
}



int main() {
    bTreeNode<int>* root = getInput();
    int p, q;
    cin >> p;
    cin >> q;

    if (find_level(root, p, 0) == find_level(root, q, 0)) {
        if (!siblings(root, p, q)) {
            cout << true;
        } else {
            cout << false;
        }
    } else {
        cout << false;
    }
}