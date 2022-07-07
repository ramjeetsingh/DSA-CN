#include <iostream>
using namespace std;

void change(char str[], char c1, char c2) {
    if (str[0] == '\0') {
        return;
    }

    if (str[0] == c1) {
        str[0] = c2;
    }
    change(str+1, c1, c2);
}

int main () {
    char str[100];
    cin.getline(str, 100);

    char c1, c2;
    cin >> c1 >> c2;

    change(str, c1, c2);
    cout << str;
}