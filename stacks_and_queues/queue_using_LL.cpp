#include <iostream>
using namespace std;

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



int main() {
    int n;
    cin >> n;

    Queue<int> q;

    for (int i = 0; i < n; i++) {
        int query;
        cin >> query;

        if (query == 1) {
            int entry;
            cin >> entry;

            q.enqueue(entry);
        }

        if (query == 2) {
            cout << q.dequeue() << endl;
        }

        if (query == 3) {
            cout << q.front() << endl;
        }
        
        if (query == 4) {
            cout << q.getSize() << endl;
        }

        if (query==5) {
            cout << q.isEmpty() << endl;
        }
    }
}