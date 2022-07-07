#include <iostream>
using namespace std;
#include <stack>


int main() {
    string brackets;
    cin >> brackets;

    stack<char> s;
    bool printed = false;

    for (int i = 0; i < brackets.length(); i++) {
        if (brackets[i] == ')') {
            if (s.empty()) {
                cout << false << endl;
                printed = true;
                break;
            } 
            s.pop();
        } else {
            s.push(brackets[i]);
        }
    }

    if (printed == false) {
        if (s.size() == 0) {
            cout << true << endl;
        } else {
            cout << false << endl;
        }
    }
    
}