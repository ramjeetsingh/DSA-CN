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

        bool printed = false;

        for (int i = 0; i <= n-2; i++) {
            if (arr[i] > arr[i+1]) {
                cout << i+1 << endl;
                printed = true;
                break;
            }
        }

        if (printed == false) {
            cout << 0 << endl;
        }

        delete[] arr;
    }
}