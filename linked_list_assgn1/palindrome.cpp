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


bool check(Node* head, int i, int j) {
    if (i >= j) {
        return true;
    }
    Node* initial_head = head;
    Node* tail = head;

    int i_temp = 0;
    while (i_temp != i) {
        head = head->next;
        i_temp += 1;
    }
    
    int j_temp = 0;
    while (j_temp != j) {
        tail = tail->next;
        j_temp += 1;
    } 

    if (head->data != tail->data) {
        return false;
    }
    return check(initial_head, i+1, j-1);
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

        cout << check(h, 0, len-1) << endl;
    }
}