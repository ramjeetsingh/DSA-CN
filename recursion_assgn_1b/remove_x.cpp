#include <iostream>
using namespace std;

#include <cstring>

void remove(char word[]) {
    int l = strlen(word);

    if (word[0] == 'x') {
        for (int i = 0; i < l; i++) {
            word[i] = word[i+1];
        }
        remove(word);
    } else if (word[0] == '\0') {
        return;
    } else {
        remove(word+1);
    }
}

int main() {
    char word[100];
    cin.getline(word, 100);

    remove(word);
    cout << word;
}