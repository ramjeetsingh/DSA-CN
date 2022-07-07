#include <iostream>
using namespace std;

void update(int arr[], int n, int x, int ind, int& k ,int ans[]) {
    if (ind == n) {
        return;
    }
    if (arr[ind] == x) {
        ans[0]= ind;
        ans++;
        k++;
    }
    update(arr, n, x, ind+1, k, ans);
}

int check(int arr[], int n, int x, int ans[]) {
    int i = 0;
    int k = 0;

    update(arr, n, x, i, k, ans);
    return k;
}

int main() {
    int n, x;
    cin >> n;

    int*arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    int*ans = new int[n];
    
    int size = check(arr, n, x, ans);
    for (int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }
    if (size == 0) {cout << -1;}

    delete [] arr;
    delete [] ans;
}