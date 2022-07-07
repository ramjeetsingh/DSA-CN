#include <iostream>
#include <cmath>
using namespace std;

int countDP(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 3;
    }

    int* arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 3;

    for (int i = 4; i <= n; i++) {
        arr[i] = ((arr[i-1] * arr[i-1]) + 2*(arr[i-1]*arr[i-2]));
    }

    int ans = arr[n];
    delete[] arr;
    return ans;

}

int balancedBT(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 3;
    }

    int for_1_less = balancedBT(n-1);
    int for_2_less = balancedBT(n-2);

    return ((for_1_less*for_1_less) + 2*(for_1_less*for_2_less));
}


int main() {
    int h;
    cin >> h;

    cout << balancedBT(h);
}