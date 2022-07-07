#include <iostream>
using namespace std;
#include "Node.cpp"

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


int find_rec(Node* head, int i, int n) {
    if (head == NULL) {
        return -1;
    }

    if (head->data == n) {
        return i;
    }

    return find_rec(head->next, i+1, n);
}


int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        Node* head = getInput();

        int n;
        cin >> n;

        cout << find_rec(head, 0, n) << endl;
    }
}