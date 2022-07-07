#include <iostream>
using namespace std;

void remove(char str[]) {
    if (str[0] == '\0') {
        return;
    }

    if (str[0] == str[1]) {
        for (int i = 1; str[i] != '\0'; i++) {
            str[i] = str[i+1];
        }
        remove(str);
    }
    remove(str+1);
}


int main() {
    char str[100];
    cin.getline(str, 100);

    remove(str);
    cout << str;
}