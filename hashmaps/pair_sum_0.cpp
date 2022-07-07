#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> map;
    int ans = 0;


    for (int i = 0; i < n; i++) {
        int remaining = 0 - arr[i];

        if (map.find(remaining) != map.end()) {
            int count = map[remaining];
            for (int j = 0; j < remaining; j++) {
                ans++;
            }
        }

        map[arr[i]]++;
    }

    cout << ans;
}