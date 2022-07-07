#include <iostream>
using namespace std;

void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = ((start + end)/2);

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

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
    int t;
    cin >> t;

    for (int q = 0; q <t; q++) {
        int n, m;
        int*arr1 = new int[n];
        int*arr2 = new int[m];

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        mergeSort(arr1, 0, n-1);
        mergeSort(arr2, 0, m-1);

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                i++;
                j++;
            } else if (arr1[i] < arr2[j]) {
                i++;
            } else {
                j++;
            }
        }

        cout << endl;

        delete[] arr1;
        delete[] arr2;
    }
}