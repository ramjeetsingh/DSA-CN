#include <iostream>
using namespace std;

void move(int n, char s, char a, char d) {
    if (n == 0) {
        return;
    }

    move(n-1, s, d, a);

    cout << s << ' ' << d << endl;

    move(n-1, a, s, d);
    return;
}


int main() {
    int n;
    cin >> n;

    char s = 'a';
    char a = 'b';
    char d = 'c';

    move(n, s, a, d);
}