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

    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;

        int*arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int num;
        cin >> num;

        mergeSort(arr, 0, n-1);

        int i = 0, j = n-1;
        int pairs = 0;

        while (i < j) {
            if (arr[i] + arr[j] == num) {
                int a = arr[i], b = arr[j];
                int no_of_a = 0, no_of_b = 0;

                while (arr[i] == a && i < j) {
                    no_of_a++;
                    i++;
                }
                if (i == j) {
                    i--;
                }

                while (arr[j] == b && i < j) {
                    no_of_b++;
                    j--;
                }

                pairs += no_of_a*no_of_b;

            } else if (arr[i] + arr[j] < num) {
                i++;
            } else {
                j--;
            }

        }

        cout << pairs << endl;


        delete[] arr;
    }
}