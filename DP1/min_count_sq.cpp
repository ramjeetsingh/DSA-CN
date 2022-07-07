#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int count(int n) {
    int* arr = new int[n+1];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    for (int i = 4; i <= n; i++) {
        arr[i] = i;                    //max possible

        for (int j = 1; j <= ceil(sqrt(n)); j++) {
            int temp = j*j;

            if (temp > i) {
                break;
            } else {
                arr[i] = min(arr[i], arr[i-temp]+1);
            }
        }
    }

    int ans = arr[n];
    delete[]arr;
    return ans;
}


int main() {
    int n;
    cin >> n;

    cout << count(n);
}