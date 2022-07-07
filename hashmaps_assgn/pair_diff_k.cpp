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

    int k;
    cin >> k;

    unordered_map<int, int> map;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int req = k + arr[i];

        if (map.find(req) != map.end()) {
            int count = map[req];
            for (int j = 0; j < count; j++) {
                ans++;
            }
        }

        if (k != 0) {
            req = arr[i]-k;

            if (map.find(req) != map.end()) {
                int count = map[req];
                for (int j = 0; j < count; j++) {
                    ans++;
                }
            }
        }

        map[arr[i]]++;
    }

    cout << ans;
}