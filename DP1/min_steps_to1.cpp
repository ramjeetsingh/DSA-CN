#include <iostream>
#include <cmath>
using namespace std;


// using DP
int countDP(int n) {
    int res[n+1];

    res[0] = 0;
    res[1] = 0;
    res[2] = 1;

    for (int i = 3; i <= n; i++) {
        int x = res[i-1], y = INT_MAX, z = INT_MAX;

        if (i%2 == 0) {
            y = res[i/2];
        }
        if (i%3 == 0) {
            z = res[i/3];
        }

        res[i] = min(x, min(y, z)) +1;
    }

    return res[n];
}


// recursive method
int count(int n) {
    if (n <= 1) {
        return 0;
    }

    int x = count(n-1);

    int y = INT_MAX;
    if (n % 2 == 0) {
        y = count(n/2);
    }

    int z = INT_MAX;
    if (n % 3 == 0) {
        z = count(n/3);
    }

    return min(x, min(y, z))+1;
}



int main() {
    int n;
    cin >> n;

    cout << countDP(n);
}