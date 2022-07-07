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
        cout << len << endl;
    }
}