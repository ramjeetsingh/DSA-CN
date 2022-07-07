#include <iostream>
using namespace std;

int min_ops(int arr[], int s, int e){
    if (s >= e-1) {
        return 0;
    }

    int ans = INT_MAX;
    for (int k = s+1; k < e; k++) {
        int ops = min_ops(arr, s, k) + min_ops(arr, k, e) + (arr[s]*arr[k]*arr[e]);\

        if (ops < ans) {
            ans = ops;
        }
    }

    return ans;
}


int main() {
    int n;
    cin >> n;

    int *size = new int[n+1];
    for (int i = 0; i <= n; i++) {
        cin >> size[i];
    }

    cout << min_ops(size, 0, n);
}