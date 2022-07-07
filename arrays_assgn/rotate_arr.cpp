#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end) {
    int i = start, j = end;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
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

        int d;
        cin >> d;

        reverse(arr, 0, n-1);
        reverse(arr, 0, n-1-d);
        reverse(arr, n-d, n-1);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        delete[] arr;
    }
}