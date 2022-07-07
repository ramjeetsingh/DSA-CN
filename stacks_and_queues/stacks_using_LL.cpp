#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        next = NULL;
    }
};


template <typename T>
class stack {
    Node<T> *head;
    int size;

    public:

    stack() {
        head = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(T element) {
        Node<T>* newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop() {
        if (size == 0) {
            return -1;
        } 

        T ans = head->data;
        head = head-> next;
        size--;
        return ans;
    }

    T top() {
        if (size == 0) {
            return 0;
        }
        return head->data;
    }
};


int main() {
    int n;
    cin >> n;

    stack<int> s;

    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;

        if (q == 1) {
            int entry;
            cin >> entry;

            s.push(entry);
        }

        if (q == 2) {
            cout << s.pop() << endl;
        }

        if (q == 3) {
            cout << s.top() << endl;
        }
        
        if (q == 4) {
            cout << s.getSize() << endl;
        }

        if (q==5) {
            cout << s.isEmpty() << endl;
        }
    }
    
}