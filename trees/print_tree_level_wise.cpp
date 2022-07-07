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
    cout << "Enter the root data" << endl;
    cin >> rootData;

    treeNode<int> *root = new treeNode<int>(rootData);

    queue<treeNode<int>*> pending;
    pending.push(root);

    while (!pending.empty()) {
        treeNode<int>* front = pending.front();
        pending.pop();

        cout << "Enter the number of child nodes of " << front->data << endl;
        int numChildren;
        cin >> numChildren;

        for (int i = 0; i < numChildren; i++) {
            int childData;
            cout << "Enter the data for " << i+1 << "th child of " << front->data << endl;
            cin >> childData;

            treeNode<int>* child = new treeNode<int>(childData);

            front->children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}


void print(treeNode<int>* root) {
    queue<treeNode<int>*> pending;
    pending.push(root);

    while (!pending.empty()) {
        treeNode<int>* front = pending.front();
        pending.pop();

        cout << front->data << ": ";

        for (int i = 0; i < front->children.size(); i++) {
            cout << front->children[i]->data << " ";   
            pending.push(front->children[i]);
        }
        cout << endl;
    }
}


int main() {
    treeNode<int> *root = getInput();

    print(root);
}