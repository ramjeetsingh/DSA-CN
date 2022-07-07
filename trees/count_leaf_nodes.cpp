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


int count(treeNode<int>* root) {
    int num = 0;

    if (root->children.size() == 0) {
        return 1;
    }

    for (int i = 0; i < root->children.size(); i++) {
        num += count(root->children[i]);
    }
    return num;
}


int main() {
    treeNode<int> *root = getInput();
    cout << count(root);
}