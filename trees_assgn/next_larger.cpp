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


void larger(treeNode<int>* root, int n, int &next_larger) {
    if (root->data > n && root->data < next_larger) {
        next_larger = root->data;
    }

    for (int i = 0; i < root->children.size(); i++) {
        larger(root->children[i], n, next_larger);
    }
}




int main() {
    treeNode<int> *root = getInput();
    int n;
    cin >> n;

    int nxt_lrg = INT_MAX;

    larger(root, n, nxt_lrg);
    if (nxt_lrg == INT_MAX) {
        cout << 0;
    } else {
        cout << nxt_lrg;
    }
}