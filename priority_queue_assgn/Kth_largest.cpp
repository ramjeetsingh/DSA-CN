#include <iostream>
#include <queue>
using namespace std;


int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < k; i++) {
        q.push(arr[i]);
    }

    for (int i = k; i < n; i++) {
        if (arr[i] > q.top()) {
            q.pop();
            q.push(arr[i]);
        }
    }

    cout << q.top();
}