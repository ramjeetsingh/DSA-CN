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


treeNode<int>* max_sum(treeNode<int>* root) {
    treeNode<int>* ans = root;

    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++) {
        sum += root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++) {
        treeNode<int>* smallAns = max_sum(root->children[i]);

        int smallSum = smallAns->data;
        for (int j = 0; j < smallAns->children.size(); j++) {
            smallSum += smallAns->children[j]->data;
        }

        if (smallSum > sum) {
            ans = smallAns;
            sum = smallSum;
        }
    }
    return ans;
}


int main() {
    treeNode<int> *root = getInput();
    
    cout << max_sum(root)->data;
}