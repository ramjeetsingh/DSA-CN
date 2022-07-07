#include <iostream>
using namespace std;

bool adder (int arr[], int n, int start, int sum_3, int sum_5) {
    if (start == n) {
        return sum_3 == sum_5;
    }

    if (arr[start] % 3 == 0) {
        sum_3 += arr[start];
    } else if (arr[start] % 5 == 0) {
        sum_5 += arr[start];
    } else {
        return adder(arr, n, start+1, sum_3+arr[start], sum_5) || adder(arr, n, start+1, sum_3, sum_5+arr[start]);
    }

    return (arr, n, start+1, sum_3, sum_5);
}


int main () {
    int n;
    cin >> n;

    int*arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << adder(arr, n, 0, 0, 0);
}