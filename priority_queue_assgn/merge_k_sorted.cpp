#include <iostream>
#include <queue>
using namespace std;

int main() {
    int k;
    cin >> k;

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;


        for (int j = 0; j < n; j++) {
            int ele;
            cin >> ele;

            q.push(ele);
        }
    }

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
}