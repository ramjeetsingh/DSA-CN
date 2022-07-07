#include <iostream>
using namespace std;

int check(int arr[], int n, int x) {
    if (n == 1) {
        bool res = (n == x) ? true : false;
        return res;
    }

    if (check(arr, n-1, x)) {
        return true;
    } else {
        bool ans = (arr[n-1] == x) ? true : false;
        return ans;
    }
}

int main() {
    int n, x;
    cin >> n;

    int*arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    cout << check(arr, n, x);

    delete [] arr;
}