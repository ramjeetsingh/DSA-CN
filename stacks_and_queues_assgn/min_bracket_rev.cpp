#include <iostream>
using namespace std;
#include <stack>
#include <cmath>

int help(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '}' && !st.empty()) {
            if (st.top() == '{') {
                st.pop();
            } else {
                st.push(str[i]);
            }
        } else {
            st.push(str[i]);
        }
    }

    int red_len = st.size();

    int n = 0;
    while (!st.empty() && st.top() == '{') {
        st.pop();
        n++;
    }

    return (red_len / 2 + n % 2);   //no of '{' /2  + no of '}'/2
}



int main() {
    string brackets;
    cin >> brackets;
    
    cout << help(brackets);
}