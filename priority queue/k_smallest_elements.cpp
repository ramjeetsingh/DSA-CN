#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    priority_queue<int> q;
    for (int i = 0; i < k; i++) {
        q.push(a[i]);
    }

    for (int i = k; i < n; i++) {
        if (a[i] < q.top()) {
            q.pop();
            q.push(a[i]);
        }
    }

    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
}