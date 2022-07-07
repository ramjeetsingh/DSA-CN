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

    int start = 0;
    int end = 0;
    int max_len = 0;

    int start_at_ind = 0;

    unordered_map<int, bool> map;
    unordered_map<int, int> index;

    for (int i = 0; i < n; i++) {
        map[arr[i]] = false;        //false shows that this number has not been considered for any subseq untill now.
        index[arr[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (map[arr[i]] == false) {
            int next_no = arr[i];
            while (map.find(next_no) != map.end()) {
                next_no++;
            }
            next_no--;

            int prev_no = arr[i];
            while (map.find(prev_no) != map.end()) {
                prev_no--;
            }
            prev_no++;

            int len_of_this_seq = abs(next_no - prev_no) + 1;
            if (len_of_this_seq > max_len || (len_of_this_seq == max_len && index[start] < start_at_ind)) {
                max_len = len_of_this_seq;

                start = prev_no;
                start_at_ind = index[start];

                end = next_no;
            }
        }
    }
    cout << start << " " << end;
}