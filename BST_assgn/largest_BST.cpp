#include <iostream>
#include <queue>
#include <cmath>
using namespace std;


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

class output {
    public:
    int minimum;
    int maximum;
    bool isBST;
    int height;
};



output helper(bTreeNode<int>* root)
{
    if(root==NULL)
    {
        output ans;
        ans.minimum=INT_MAX;
        ans.maximum=INT_MIN;
        ans.height=0;
        ans.isBST=true;
        return ans;
    }
    
    
    output Left = helper(root->left); 
    output Right = helper(root->right);
    
    if(!(Left.isBST && Left.maximum < root->data))
        Left.isBST=false;
    
    if(!(Right.isBST && Right.minimum > root->data))
        Right.isBST=false;
    
    
    if(!Left.isBST || !Right.isBST ||  root->data >Right.minimum ||  root->data <Left.maximum)
    {
        if(Left.height>Right.height)
        {
            Left.isBST=false;
            return Left;
            
        }
        
        else
        {
            Right.isBST=false;
            return Right;
        }
        
    }
    output ans;
    ans.isBST=true;
    ans.minimum=min(Left.minimum,min(root->data,Right.minimum));
    ans.maximum=max(Left.maximum,max(root->data,Right.maximum));
    ans.height=max(Left.height,Right.height)+1;
    return ans;
}



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


int main() {
    bTreeNode<int>* root = getInput();

    output ans = helper(root);
    cout << ans.height;
}