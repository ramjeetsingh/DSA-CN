#include <iostream>
using namespace std;
#include "sll.cpp"

Node* getInput() {
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1) {
        Node *newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

Node* insert_rec(Node* head, Node* a, int i, int n, int count) {
    if (i == 0) {
        Node* newNode = new Node(n);
        newNode -> next = head;
        head = newNode;
        return head;
    }

    if (count == i-1) {
        Node* newNode = new Node(n);
        Node* temp = a;

        newNode -> next = temp -> next;
        temp -> next = newNode;
        return head;
    }

    return insert_rec(head, a -> next, i, n, count+1);
}



void print(Node* head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}



int main() {
    int t;
    cin >> t;

    for (int q =0; q < t; q++) {
        Node *h = getInput();

        int len = 0;
        Node *temp = h;
        while (temp != NULL) {
            len++;
            temp = temp -> next;
        }
        
        int i , n;
        cin >> i >> n;

        if (i > len) {
            print(h);
        } else {
            h = insert_rec(h, h, i, n, 0);
            print(h);
        }
    }
}