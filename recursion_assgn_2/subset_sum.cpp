#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;

int sum_arr(vector<int> subset, int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += subset[i];
    }
    return ans;
}


void help(vector<int> &subset, int n, int i, int k, vector<int> &arr) {
    if (i == arr.size()) {
        if (sum_arr(subset, subset.size()) == k) {
            subsets.push_back(subset);
        }
        return;
    }

    help(subset, n, i+1, k, arr);

    subset.push_back(arr[i]);
    help(subset, n, i+1, k, arr);
    subset.pop_back();
}


int main () {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    vector<int> empty;
    help(empty, n, 0, k, arr);

    for(auto x:subsets) {
        for (auto y:x) {
            cout << y << " ";
        }
        cout << endl;
    }

}