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

        int i;
        cin >> i;

        int ind = 0;
        bool printed = false;
        Node *temp = h;
        while (temp != NULL) {
            if (ind == i) {
                cout << temp -> data << endl;
                printed = true;
                break;
            }
            ind++;
            temp = temp -> next;
        }
        if (printed == false) {
            cout << "i out of range" << endl;
        }
    }
}