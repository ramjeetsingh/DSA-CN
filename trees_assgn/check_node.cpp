#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class treeNode {
    public:
    T data;
    vector<treeNode<T> *> children;

    treeNode(T data) {
        this ->data = data;
    }
};


treeNode<int>* getInput() {
    int rootData;
    cin >> rootData;

    treeNode<int> *root = new treeNode<int>(rootData);

    queue<treeNode<int>*> pending;
    pending.push(root);

    while (!pending.empty()) {
        treeNode<int>* front = pending.front();
        pending.pop();

        int numChildren;
        cin >> numChildren;

        for (int i = 0; i < numChildren; i++) {
            int childData;
            cin >> childData;

            treeNode<int>* child = new treeNode<int>(childData);

            front->children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}


bool check(treeNode<int>* root, int x) {
    if (root->data == x) {
        return true;
    }

    for (int i = 0; i < root->children.size(); i++) {
        bool smallAns = check(root->children[i], x);
        if(smallAns == true) {
            return true;
        }
    }
    return false;
}


int main() {
    treeNode<int> *root = getInput();
    int x;
    cin >> x;

    cout << check(root, x);
}