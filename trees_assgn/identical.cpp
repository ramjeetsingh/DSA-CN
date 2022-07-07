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


bool check(treeNode<int>* root1, treeNode<int>* root2) {
    if ((root1->data != root2->data) || (root1->children.size() != root2->children.size())) {
        return false;
    }

    for (int i = 0; i < root1->children.size(); i++) {
        bool smallAns = check(root1->children[i], root2->children[i]);
        if (smallAns == false) {
            return false;
        }
    }
    return true;
}




int main() {
    treeNode<int> *root1 = getInput();
    treeNode<int> *root2 = getInput();

    cout << check(root1, root2);
}