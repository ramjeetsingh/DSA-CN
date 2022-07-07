#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i< n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        if (freq.count(arr[i]) == 0) {
            freq[arr[i]] = 1;
        } else {
            freq[arr[i]] += 1;
        }
    }

    int max_occ_no = 0;
    int max_occ = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] > max_occ) {
            max_occ = freq[arr[i]];
            max_occ_no = arr[i];
        }
    }

    cout << max_occ_no;

}