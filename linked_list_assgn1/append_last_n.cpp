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


void print(Node* head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

Node* help(Node* head, int n, int len) {
    int i = len-n;    //index to which the head will point
    Node* ind_0 = head;
    Node* temp = head;

    for (int j = 0; j < i-1; j++) {
        temp = temp->next;
    }

    head = temp -> next;
    temp -> next = NULL;

    Node* temp2 = head;
    while (temp2 -> next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = ind_0;
    return head;
}



int main() {
    int t;
    cin >> t;

    for (int q =0; q < t; q++) {
        Node *h = getInput();

        int n;
        cin >> n;

        int len = 0;
        Node* temp = h;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        if (n == 0 || n == len) {
            print(h);
        } else {
            h = help(h, n, len);
            print(h);
        }
    }
}