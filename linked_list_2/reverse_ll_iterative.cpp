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

Node* reverse_ite(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    Node* next = current->next;

    while (current != NULL) {
        // current -> next = prev;
        // prev = current;
        // current = current->next;
        // if (current != NULL) {
        //     next = current->next;
        // }
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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

        h = reverse_ite(h);
        print(h);
    }
}