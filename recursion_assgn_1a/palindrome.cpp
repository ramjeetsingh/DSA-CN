#include <iostream>
using namespace std;

bool check(char s[], int i, int j) {
    if (i >= j) {
        return true;
    }

    if (s[i] == s[j]) {
        return check(s, ++i, --j);
    } else {
        return false;
    }
}

int main() {
    char s[10];
    cin >> s;

    int size = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        size++;
    }

    int i = 0;
    int j = size-1;

    cout << check(s, i, j);
}