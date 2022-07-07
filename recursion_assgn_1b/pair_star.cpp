#include <iostream>
using namespace std;

#include <cstring>

void star(char str[], int len) {
    if (str[0] == '\0') {
        return;
    } else if (str[0] == str[1]) {
        for (int i = len; i > 0; i--) {
            str[i+1] = str[i];
        }
        str[1] = '*';
        star(str+2, len+1);
    } else {
        star(str+1, len);
    }
}


int main() {
    char str[100];
    cin.getline(str, 100);

    int len = strlen(str);

    star(str, len);
    cout << str;
}