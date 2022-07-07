#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int* dp = new int[n];

    dp[0] = arr[0];
    dp[1] = max(arr[1], dp[0]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(arr[i] + dp[i-2], dp[i-1]);
    }

    cout << dp[n-1];
}