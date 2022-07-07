#include <iostream>
#include <algorithm>
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


Node* swap_nodes(Node* head, int i, int j) {
    if(i>j){
        i=i+j;
        j=i-j;
        i=i-j;
    }
    if(i==0){
        if(j==1){
            Node *cur=head->next;
            head->next=cur->next;
            cur->next=head;
            return cur;
        }
        Node *pt=head;
        for(int c=1;c<j;c++)
            pt=pt->next;
        
        Node *temp=head->next;
        Node *cur=pt->next;
        
        head->next=cur->next;
        pt->next=head;
        cur->next=temp;
        return cur;
        
    }
    if(j-i==1){
        Node * pt=head;
        for(int c=1;c<i;c++)
            pt=pt->next;
        
        Node* cur=pt->next;
        Node* cur1=cur->next;
        
        cur->next=cur1->next;
        pt->next=cur1;
        cur1->next=cur;
        return head;
        
    }
    Node* pt1=head;
    Node *pt2=head;
    
    for(int c=1;c<i;c++)
        pt1=pt1->next;
    
    for(int c=1;c<j;c++)
        pt2=pt2->next;
    
    Node *cur1=pt1->next;
    Node *cur2=pt2->next;
    
    Node *temp=cur1->next;
    
    cur1->next=cur2->next;
    pt2->next=cur1;
    pt1->next=cur2;
    cur2->next=temp;
    
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
    for (int q = 0; q < t; q++) {
        Node* head = getInput();

        int i, j;
        cin >> i >> j;

        head = swap_nodes(head, i, j);
        print(head);
    }
}