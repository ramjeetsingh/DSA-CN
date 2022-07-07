#include <iostream>
using namespace std;

string checkWinner(int n, int x, int y) {
    bool *arr = new bool[n+1];

    arr[0] = false;
    arr[1] = true;
    arr[x] = true;
    arr[y] = true;

    for (int i = 2; i <= n; i++) {
        if (i == x || i == y) {
            continue;
        }
        else {
            if (!arr[i-1]) {
                arr[i] = true;
            } else if (i-x >= 0 && !arr[i-x]) {
                arr[i] = true;
            } else if (i-y >= 0 && !arr[i-y]) {
                arr[i] = true;
            } else {
                arr[i] = false;
            }
        }
    }

    if (arr[n] == true) {
        return "Beerus";
    } else {
        return "Whis";
    }
}


int main() {
    int n, x, y;
    cin >> n >> x >> y;

    cout << checkWinner(n, x, y);
}