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
        int ele;
        cin >> ele;

        s.push(ele);        
    }

    stack<int> s2;

    int len = s.getSize();

    for (int i = 0; i < len; i++) {
        s2.push(s.pop());
    }

    for (int i = 0; i < n; i++) {
        cout << s2.pop() << " ";
    }
}