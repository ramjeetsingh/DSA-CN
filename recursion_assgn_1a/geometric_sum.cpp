#include <iostream>
using namespace std;

#include <bits/stdc++.h>

double geo_sum(int n) {
    if (n == 0) {
        return 1;
    }

    return double(1/pow(2,n)) + geo_sum(n-1);
}

int main() {
    int k;
    cin >> k;

    cout << geo_sum(k);
}