#include <iostream>
using namespace std;

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

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = ans^arr[i];
        }

        cout << ans << endl;

        delete[] arr;
    }
}

