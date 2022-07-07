#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> min_h;   //second part of the arr
    priority_queue<int> max_h;                              //first part of the arr

    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;

        if(i %2 == 0) {
            if (min_h.size() == 0 && max_h.size()==0) {
                max_h.push(ele);
            } else {
                if (ele > max_h.top()) {
                    min_h.push(ele);
                } else {
                    max_h.push(ele);
                }
            }

            if (max_h.size() > min_h.size()) {
                cout << max_h.top() << endl;
            } else {
                cout << min_h.top() << endl;
            }

        } else {
            if (ele > max_h.top()) {
                min_h.push(ele);
            } else {
                max_h.push(ele);
            }


            if (max_h.size() > 1 + min_h.size()) {
                min_h.push(max_h.top());
                max_h.pop();
            } else if (min_h.size() > 1 + max_h.size()) {
                max_h.push(min_h.top());
                min_h.pop();
            }

            cout << (max_h.top() + min_h.top())/2 << endl;
        }

    }
}