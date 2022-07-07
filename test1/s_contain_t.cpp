#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    int i = 0, j = 0;

    int last_common_at = -1;
    bool while_broken = false;

    while (j < m) {
        bool found_this_character = false;
        for (int i = last_common_at+1; i < n; i++) {
            if (s[i] == t[j]) {
                last_common_at = i;
                found_this_character = true;
                j++;  
            }
        }

        if (found_this_character == false) {
            while_broken = true;
            break;
        }
    }

    if (while_broken) {
        cout << false;
    } else {
        cout << true;
    }
}