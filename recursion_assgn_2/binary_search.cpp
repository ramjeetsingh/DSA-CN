#include <iostream>
using namespace std;

int binSearch(int arr[], int n, int x, int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right-left)/2;

    if (arr[mid] == x) {
        return mid;
    } else if (arr[mid] < x) {
        return binSearch(arr, n, x, mid+1, right);
    } else {
        return binSearch(arr, n, x, left, mid-1);
    }
}


int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    cout << binSearch(arr, n, x, 0, n-1);
}
