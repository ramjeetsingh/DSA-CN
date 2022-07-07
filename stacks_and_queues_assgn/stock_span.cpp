#include <iostream>
using namespace std;
#include <stack>

int ss(stack<int> st) {
    int ans = 1;
    int stock_price = st.top();
    st.pop();

    while (st.size() != 0 && st.top() < stock_price) {
        ans++;
        st.pop();
    }

    return ans;
}


int main() {
    int n;
    cin >> n;

    int *rates = new int[n];
    int *spans = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> rates[i];
    }

    stack<int> st;

    for (int i = 0; i < n; i++) {
        st.push(rates[i]);
        int temp = ss(st);
        spans[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << spans[i] << " ";
    }
    cout << endl;
}