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

//Method 1
void reverse(Node* head) {
    if (head->next == NULL) {
        cout << head->data << " ";
        return;
    }

    reverse(head->next);
    cout << head->data << " ";
    return;
}

//Method 2
Node* reverse_2 (Node*head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* smallAns = reverse_2(head->next);

    Node* temp = smallAns;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head;
    head->next = NULL;
    return smallAns; 
}


//Method 3

class Pair {
    public:
        Node* head;
        Node* tail;
};

Pair reverse_3(Node* head) {
    if (head == NULL || head->next == NULL) {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverse_3(head->next);

    smallAns.tail -> next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}


//Method 4
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



int main() {
    int t;
    cin >> t;

    for (int q =0; q < t; q++) {
        Node *h = getInput();

        reverse(h);
        cout << endl;
    }
}