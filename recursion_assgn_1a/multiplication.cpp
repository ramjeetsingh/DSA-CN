#include <iostream>
using namespace std;

int multiply(int m, int n) {
    if (m == 1) {
        return n;
    }

    return n + multiply(m-1, n);
}

int main() {
    int m , n;
    cin >> m >> n;

    cout << multiply(m,n);
}