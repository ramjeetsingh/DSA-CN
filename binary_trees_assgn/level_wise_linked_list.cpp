#include <iostream>
#include <queue>
using namespace std;

class NodeLL {
    public:
    int data;
    NodeLL *next;

    NodeLL(int data) {
        this -> data = data;
        next = nullptr;
    }
};


template <typename T>
class bTreeNode {
    public:
    T data;
    bTreeNode<T>* left;
    bTreeNode<T>* right;

    bTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~bTreeNode() {
        delete left;
        delete right;
    }
};


bTreeNode<int>* getInput() {
    int rootData;
    cin >> rootData;

    if (rootData == -1) {
        return NULL;
    }

    bTreeNode<int>* root = new bTreeNode<int>(rootData);
    queue<bTreeNode<int>*> pending;

    pending.push(root);

    while (!pending.empty()) {
        bTreeNode<int>* front = pending.front();
        pending.pop();

        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            bTreeNode<int>* leftNode = new bTreeNode<int>(leftData);
            front->left = leftNode;
            pending.push(leftNode);
        }

        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            bTreeNode<int>* rightNode = new bTreeNode<int>(rightData);
            front->right = rightNode;
            pending.push(rightNode);
        }
    }
    return root;
}

void help(bTreeNode<int>* root, vector<NodeLL*> &ans) {
    queue<bTreeNode<int>*> pending;
    pending.push(root);

    bTreeNode<int>* null_node = new bTreeNode(-1);
    pending.push(null_node);

    NodeLL* head_of_level = new NodeLL(-1);
    NodeLL* temp = head_of_level;

    while (!pending.empty()) {
        bTreeNode<int>* front = pending.front();
        pending.pop();

        if (front->data == -1) {
            if (pending.empty()) {
                temp->next = NULL;
                ans.push_back(head_of_level);
                break;
            }
            
            pending.push(null_node);

            temp->next = NULL;
            ans.push_back(head_of_level);
            head_of_level = new NodeLL(-1);
            temp = head_of_level;
        } else {
            if (front->left != NULL) {
                pending.push(front->left);
            }
            if (front->right != NULL) {
                pending.push(front->right);
            }

            NodeLL* newNode = new NodeLL(front->data);

            if (head_of_level->data == -1) {
                head_of_level = newNode;
                temp = head_of_level;
            } else {
                temp->next = newNode;
                temp = temp->next;
            } 
        }
    }
}

void printLL(NodeLL* head) {
    if (head->next == NULL) {
        cout << head->data;
        return;
    }

    cout << head->data << " ";
    printLL(head->next);
}


int main() {
    bTreeNode<int>* root = getInput();
    vector<NodeLL*> ans;
    help(root, ans);
    
    for (int i = 0; i < ans.size(); i++) {
        NodeLL* newHead = ans[i];
        printLL(newHead);
        cout << endl;
    }
}