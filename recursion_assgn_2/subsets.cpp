#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<std::vector<int>> subsets;

void help(vector<int> &subset, int i, vector<int> &arr) {
    if (i == arr.size()) {
        subsets.push_back(subset);
        return;
    }

    help(subset, i+1, arr);

    subset.push_back(arr[i]);
    help(subset, i+1, arr);
    subset.pop_back();
}



int main () {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> empty;
    help(empty, 0, arr);

    for (auto subset: subsets) {
        for (auto y: subset) {
            cout << y << " ";
        }
        cout << endl;
    }
}