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


// method 1

int maximum(bTreeNode<int>* root) {
    if (root == NULL) {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(bTreeNode<int>* root) {
    if (root == NULL) {
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool check(bTreeNode<int>* root) {
    if (root == NULL) {
        return true;
    }

    if (root->left != NULL) {
        if (root->data < root->left->data) {
            return false;
        }
    }
    if (root->right != NULL) {
        if (root->data > root->right->data) {
            return false;
        }
    }

    int left_max = maximum(root->left);
    int right_min = minimum(root->right);

    return check(root->left)&&check(root->right) && (root->data > left_max) && (root->data <= right_min);
}


// method 2 (better TC)

class check2Return {
    public:
    bool ifBST;
    int maximum;
    int minimum;
};

check2Return check2(bTreeNode<int>* root) {
    if (root == NULL) {
        check2Return output;
        output.ifBST = true;
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        return output;
    }

    check2Return leftAns = check2(root->left);
    check2Return rightAns = check2(root->right);

    int maximum = max(root->data , max(leftAns.maximum, rightAns.maximum));
    int minimum = min(root->data, min(leftAns.minimum, rightAns.minimum));

    bool isBSTFinal = ((root->data > leftAns.maximum) && (root->data <= rightAns.minimum) && check2(root->left).ifBST && check2(root->right).ifBST);
    check2Return output;
    output.ifBST = isBSTFinal;
    output.maximum = maximum;
    output.minimum = minimum;
    return output;
}


//method 3 (good TC and easier) 

bool check3(bTreeNode<int>* root, int min = INT_MAX, int max = INT_MIN) {
    if (root == NULL) {
        return true;
    }

    bool ifLeftGood = check3(root->left, min, root->data - 1);
    bool ifRightGood = check3(root->right, root->data, max);
    return ifLeftGood && ifRightGood;
}



int main() {
    bTreeNode<int>* root = getInput();
    cout << check2(root).ifBST;
}