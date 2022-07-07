#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> turn;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;

        turn.push(ele);
        pq.push(ele);
    }

    int k;
    cin >> k;

    int time = 0;

    while (true) {
        if (turn.front() == pq.top()) {
            if (k == 0) {
                break;
            }
            time++;
            turn.pop();
            pq.pop();
            k--;
        } else {
            if (k == 0) {
                k = turn.size()-1;
            } else {
                k--;
            }
            turn.push(turn.front());
            turn.pop();
        }     
    }

    cout << time+1;
}