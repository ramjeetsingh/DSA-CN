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


int sum_of_nodes(treeNode<int>* root, int ans) {
    ans += root->data;

    if (root->children.size() == 0) {
        return ans;
    }

    for (int i = 0; i < root->children.size(); i++) {
        ans = sum_of_nodes(root->children[i], ans);
    }
    return ans;
}


int main() {
    treeNode<int> *root = getInput();
    cout << sum_of_nodes(root ,0);
}