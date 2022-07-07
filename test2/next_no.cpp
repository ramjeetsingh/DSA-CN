#include <iostream>
using namespace std;

class node {
    public:

    int data;
    node* next;

    node(int data) {
        this->data = data;
        next = NULL;
    }
};

node* getinput() {
    int data;
    cin >> data;

    node* head = NULL;
    node* tail = NULL;

    while (data != -1) {
        node* newNode = new node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

node* rev(node* head) {
    node* prev_part = NULL;
    while (head->next != NULL) {
        node* temp = head->next;
        head->next = prev_part;
        prev_part = head;
        head = temp;
    }

    head->next = prev_part;
    return head;
}

void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}



int main() {
    node* head = getinput();

    head = rev(head);

    node* temp = head;

    while (temp->next != NULL) {
        if (temp -> data == 9) {
            temp->data = 0;
            temp = temp->next;
        } else {
            temp->data += 1;
            break;
        }
    }

    if (temp->next == NULL) {
        if (temp->data == 9) {
            node* lastNode = new node(1);
            temp->data = 0;
            temp->next = lastNode;
        } else {
            temp->data++;
        }
    }

    head = rev(head);
    print(head);
}