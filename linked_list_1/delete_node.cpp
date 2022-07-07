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


Node* del(Node* head, int pos) {
    int i = 0;
    Node* temp = head;

    while (i < pos-1) {
        temp = temp -> next;
        i++;
    }
    Node* a = temp -> next;

    if (pos == 0) {
        head = a;
    } else {
        a = a -> next;
        temp -> next = a;
    }
    return head;
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
            h = del(h, pos);
            print(h);
        }
    }
}