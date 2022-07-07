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


Node* reverse_2 (Node*head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* smallAns = reverse_2(head->next);

    Node* tail = head -> next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}



void print(Node* head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}



Node* rev(Node* head, int start, int end) {
    Node* temp = head;
    Node* before_start = head;
    int ind = 0;
    while (ind < end) {
        if (ind < start-1) {
            before_start = before_start->next;
        }
        temp = temp->next;
        ind++;

        if (temp->next == NULL) {
            break;
        }
    }

    Node* remaining = temp->next;

    temp->next = NULL;

    Node* reversed = NULL;

    if (start == 0) {
        reversed = reverse_2(before_start);
    } else {
        reversed = reverse_2(before_start->next);
    }


    if (start != 0) {
        before_start->next = reversed;
    }

    Node* reversed_temp = reversed;

    while (reversed->next != NULL) {
        reversed = reversed->next;
    }

    reversed->next = remaining;


    if (start == 0) {
        return reversed_temp;
    } else {
        return head;
    }

}




int main() {
    int t;
    cin >> t;

    for (int q =0; q < t; q++) {
        Node *h = getInput();

        int k;
        cin >> k;

        int len = 0;
        Node* temp_len = h;
        while (temp_len != NULL) {
            len++;
            temp_len = temp_len->next;
        }

        if (k == 0) {
            print(h);
        } else {
            int i = 0;
            while (i < len) {
                h = rev(h, i, i + k - 1);
                i += k;
            }
            print(h);
        }

    }
}