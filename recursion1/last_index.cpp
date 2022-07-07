#include <iostream>
using namespace std;

int check(int arr[], int n , int x, int ind, int last_index) {
    if (n == 1) {
        if (arr[ind] == x) {
            last_index = ind;
        }
        return last_index;
    }

    if (arr[ind] == x) {
        last_index = ind;
    }

    int next_check = check(arr, n-1, x, ind+1, last_index);
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

    int last_ind = -1;
    last_ind = check(arr, n, x, 0, last_ind);
    cout << last_ind;

    delete [] arr;
}