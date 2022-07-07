#include <iostream>
using namespace std;
#include <cmath>

template <typename T>
class Node {
    public :

    T data;
    Node<T> * next;

    Node(T data) {
        this ->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue {
    Node<T> * head;
    Node<T> * tail;
    int size;

    public:

    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size==0;
    }

    void enqueue(T data) {
        Node<T> * newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T front() {
        if (size == 0) {
            return -1;
        }
        return head->data;
    }

    T dequeue() {
        if (size == 0) {
            return -1;
        }
        T ans = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;           // deletes the node from memory
        size--;
        return ans;
    }
};


void rev_q(Queue<int> &q) {
    if (q.getSize() <= 1) {
        return;
    }

    int top = q.front();
    q.dequeue();
    rev_q(q);
    q.enqueue(top);
}



int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        Queue<int> q;
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            int ele;
            cin >> ele;

            q.enqueue(ele);
        }

        rev_q(q);

        for (int j = 0; j < n; j++) {
            cout << q.dequeue() << " ";
        }
        cout << endl;
    }      
}