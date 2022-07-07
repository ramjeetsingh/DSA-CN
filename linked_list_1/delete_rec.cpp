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

Node* del_rec(Node* head, Node* a, int i, int count) {
    if (i==0) {
        head = a -> next;
        return head;
    }

    if (count == i-1) {
        Node* temp = a -> next;
        a -> next = temp -> next;
        return head;
    }

    return del_rec(head, a -> next, i, count+1);
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

        int pos;
        cin >> pos;

        int len = 0;
        Node *temp = h;
        while (temp != NULL) {
            len++;
            temp = temp -> next;
        }

        if (pos >= len) {
            print(h);
        } else {
            h = del_rec(h, h, pos, 0);
            print(h);
        }
    }
}