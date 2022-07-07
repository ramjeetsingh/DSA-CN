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

    void insert_f(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else if (size == 10) {
            cout << -1 << endl;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insert_r(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail == NULL) {
            tail = newNode;
            head = newNode;
        } else if (size == 10) {
            cout << -1 << endl;
            return;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void delete_f() {
        if (size == 0) {
            cout << -1 << endl;
            return;
        } else if (tail == head) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
        }
        size--;
    }

    void delete_r() {
        if (size == 0) {
            cout << -1 << endl;
            return;
        } else if (tail == head) {
            head = NULL;
            tail = NULL;
        } else {
            Node<T>* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            tail = temp;
            tail->next = NULL;
        }
        size--;
    }

    T get_f() {
        if (size == 0) {
            return -1;
        }
        return head->data;
    }

    T get_r() {
        if (size == 0) {
            return -1;
        }
        return tail->data;
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

            q.insert_f(entry);
        }

        if (query == 2) {
            int entry;
            cin >> entry;

            q.insert_r(entry);
        }

        if (query == 3) {
            q.delete_f();
        }

        if (query == 4) {
            q.delete_r();
        }
        
        if (query == 5) {
            cout << q.get_f() << endl;
        }

        if (query==6) {
            cout << q.get_r() << endl;
        }
    }
}