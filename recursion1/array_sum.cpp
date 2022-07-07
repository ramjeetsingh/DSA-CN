#include <iostream>
using namespace std;

int array_sum(int arr[], int n){
    if (n == 1) {
        return arr[0];
    }

    return array_sum(arr, n-1) + arr[n-1];
}

int main() {
    int n;
    cin >> n;

    int*arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << array_sum(arr, n);
}