#include <iostream>
using namespace std;
#include "sll.cpp"

Node* getInput() {
    int data;
    cin >> data;

    Node* head = NULL;
    Node* tail = NULL;

    while (data != -1) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
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


Node* merge(Node*h1, Node*h2) {
    int i = 0;
    Node* temp1 = h1;

    while (temp1 != NULL && h2 != NULL) {
        if (temp1->data <= h2->data) {
            temp1 = temp1->next;
            i++;
        } else {
            h1 = insert_rec(h1, h1, i, h2->data, 0);
            h2 = h2->next;
            i++;
        }
    }

    while (h2 != NULL) {
        h1 = insert_rec(h1, h1, i, h2->data, 0);
        h2 = h2->next;
        i++;
    }

    return h1;
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

    for (int q = 0; q < t; q++) {
        Node *h1 = getInput();
        Node *h2 = getInput();

        h1 = merge(h1, h2);
        print(h1);
    }
}