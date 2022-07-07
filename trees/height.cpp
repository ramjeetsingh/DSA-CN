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


int height(treeNode<int>* root) {
    if (root->children.size() == 0) {
        return 0;
    }

    int max_ht_of_this_subtree = 0;
    for (int i = 0; i < root->children.size(); i++) {
        int current_ht = 1 + height(root->children[i]);
        if (current_ht > max_ht_of_this_subtree) {
            max_ht_of_this_subtree = current_ht;
        }
    }
    return max_ht_of_this_subtree;
}


int main() {
    treeNode<int> *root = getInput();
    cout << 1 + height(root);
}