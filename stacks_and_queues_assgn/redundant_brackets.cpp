#include <iostream>
using namespace std;
#include <stack>


bool check(string &str) {
    stack<char> s;

    for (auto x:str) {
        if (x == ')') {
            char top = s.top();
            s.pop();

            bool ans = true;
            
            while (s.size() != 0 && top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    ans = false;
                }
                top = s.top();
                s.pop();
            }
            if (ans == true) {
                return true;
            }
        } else {
            s.push(x);
        } 
    }
    return false;
}


int main() {
    string str;
    cin >> str;

    cout << check(str);
}