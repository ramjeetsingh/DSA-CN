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


void find(treeNode<int>* root, int &largest, int &sec_largest) {
    if (root->data > largest) {
        sec_largest = largest;
        largest = root->data;
    } else if (root->data > sec_largest) {
        sec_largest = root->data;
    }

    for (int i = 0; i < root->children.size(); i++) {
        find(root->children[i], largest, sec_largest);
    }
}



int main() {
    treeNode<int> *root = getInput();

    int largest = INT_MIN;
    int sec_largest = INT_MIN;

    find(root, largest, sec_largest);

    if (sec_largest == INT_MIN) {
        cout << 0;
    } else {
        cout << sec_largest;
    }

}