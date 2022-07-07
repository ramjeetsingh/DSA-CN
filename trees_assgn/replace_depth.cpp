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

void replace(treeNode<int>* root, int &depth) {
    root->data = depth;

    for (int i = 0; i < root->children.size(); i++) {
        replace(root->children[i], ++depth);
        depth--;
    }
}

void print(treeNode<int>* root)
{
    queue<treeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
 
        treeNode<int>* first = q.front();
        q.pop();
 
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
 
        cout << first->data << " ";
 
        for (int i = 0; i < first->children.size(); i++) {
            q.push(first->children[i]);
        }
    }
}


int main() {
    treeNode<int> *root = getInput();

    int depth = 0;
    replace(root, depth);

    print(root);

}