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


Node* delete_n(Node* head, int len, int m, int n) {
    int check_for_end = m-1;
    int grps_deleted = 0;
    while (check_for_end < len) {
        int check = 0;
        while (check < n) {
            head = del_rec(head, head, m*(1+grps_deleted), 0);
            len--;
            check++;
            if (check_for_end >= len-1) {
                break;
            }
        }
        grps_deleted++;
        check_for_end += m;
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

        int m, n;
        cin >> m >> n;

        int len = 0;
        Node *temp = h;
        while (temp != NULL) {
            len++;
            temp = temp -> next;
        }

        h = delete_n(h, len, m, n);
        print(h);
    }
}