#include <iostream>
using namespace std;

#include <cstring>

void replace(char input[]) {
    int l = strlen(input);

    if (input[0] == 'p') {
        if (input[1] == 'i') {
            for(int i = l; i > 1; i--) {
                input[i+2] = input[i];
            }
            input[0] = '3';
            input[1] = '.';
            input[2] = '1';
            input[3] = '4';
            replace(input+4);
        }
    } else if (input[0] != '\0') {
        replace(input+1);
    } else {
        return;
    }
}

int main() {
    char str[1000];
    cin.getline(str, 1000);

    int size = strlen(str);

    replace(str);
    cout << str;
}