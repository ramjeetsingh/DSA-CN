#include <iostream>
using namespace std;

int check(int arr[], int n , int x, int ind) {
    if (arr[ind] == x) {
        return ind;
    }

    if (n == 1) {
        return -1;   
    }

    int next_check = check(arr, n-1, x, ind+1);
    return next_check;
}

int main() {
    int n, x;
    cin >> n;

    int*arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    int ind = -1;
    ind = check(arr, n, x, 0);
    cout << ind;

    delete [] arr;
}