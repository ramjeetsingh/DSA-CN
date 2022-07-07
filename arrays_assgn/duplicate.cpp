#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int q = 0; q<t; q++) {
        int n;
        cin >> n;

        int*arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int ideal_sum = (n-1)*n/2;  // sum of 1 to (n-1) i.e. no repetitions

        int actual_sum = 0;
        for (int i = 0; i < n; i++) {
            actual_sum += arr[i];
        }

        int diff = ideal_sum - actual_sum;

        cout << ((n-1)-diff) << endl;

        delete[] arr;
    }
}