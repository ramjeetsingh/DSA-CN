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
    int max_len = -1;
    int sum_till_now = 0;

    for (int i = 0; i < n; i++) {
        sum_till_now += arr[i];

        if (map.find(sum_till_now) != map.end()) {
            int len_of_this = i - map[sum_till_now];
            if (len_of_this > max_len) {
                max_len = len_of_this;
            }
        } else {
            map[sum_till_now] = i;
        }
    }
    cout << max_len;
}