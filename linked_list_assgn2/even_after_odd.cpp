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


Node* arrange(Node* head) {
    Node * oHead=NULL;
    Node * oTail=NULL;
    Node * eHead=NULL;
    Node * eTail=NULL;
  
    while(head!=NULL) {
        if((head->data)%2!=0) {
            if(oHead==NULL) {
                oHead=head;
                oTail=head;
            } else {
                oTail->next=head;
                oTail=head;
            }
        } else {
            if(eHead==NULL) {
                eHead=head;
                eTail=head;
            } else{
                eTail->next=head;
                eTail=head;
            }
        }
        head=head->next;
    }
  
  
    if(oHead==NULL)
        return eHead;
    else if(eHead==NULL)
        return oHead;
    else { 
        oTail->next=eHead;
        eTail->next=NULL;
        return oHead;
    }   
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
    for (int q = 0; q < t; q++) {
        Node* head = getInput();

        head = arrange(head);
        print(head);
    }
}