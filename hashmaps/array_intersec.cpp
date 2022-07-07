#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;

        int* arr1 = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        int m;
        cin >> m;

        int* arr2 = new int[m];
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        unordered_map<int, int> freq_arr2;

        for (int i = 0; i < m; i++) {
            if (freq_arr2.count(arr2[i]) == 0) {
                freq_arr2[arr2[i]] = 1;
            } else {
                freq_arr2[arr2[i]] += 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (freq_arr2.count(arr1[i]) != 0 && freq_arr2[arr1[i]] > 0) {
                cout << arr1[i] << " ";
                freq_arr2[arr1[i]]--;
            }
        }
        cout << endl;
    }
}