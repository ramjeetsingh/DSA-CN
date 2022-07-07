#include <iostream>
using namespace std;

int count(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if (n == 3) {
        return 4;
    }

    return count(n-3)+count(n-2)+count(n-1);
}


int main() {
    int n;
    cin >> n;

    cout << count(n);
}