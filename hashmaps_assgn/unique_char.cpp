#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;

    string ans = "";

    unordered_map<char, bool> letters;

    for (auto x: s) {
        if (letters.find(x) == letters.end()) {
            letters[x] = true;
            ans += x;
        }
    }

    cout << ans;
}