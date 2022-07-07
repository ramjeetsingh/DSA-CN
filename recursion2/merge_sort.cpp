#include <iostream>
using namespace std;

void sort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = ((start + end)/2);

    sort(arr, start, mid);
    sort(arr, mid+1, end);

    int l1 = mid - start +1;
    int l2 = end - mid;

    int a[l1], b[l2];
    for (int i = 0; i < l1; i++) {
        a[i] = arr[i + start];
    }

    for (int j = 0; j < l2; j++) {
        b[j] = arr[j + mid+1];
    }

    int i = 0, j = 0, k = start;

    while (i < l1 && j < l2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < l1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < l2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}


int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}