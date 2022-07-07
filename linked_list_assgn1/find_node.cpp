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

int find(Node* head, int n) {
    int ans = -1;
    int ind = 0;
    while (head != NULL) {
        if (head -> data == n) {
            ans = ind;
            break;
        } else {
            ind++;
            head = head->next;
        }
    }
    return ans;
}



int main() {
    int t;
    cin >> t;

    for (int q =0; q < t; q++) {
        Node *h = getInput();

        int n;
        cin >> n;

        cout << find(h, n) << endl;
    }
}