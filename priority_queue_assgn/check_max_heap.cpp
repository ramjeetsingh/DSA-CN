#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool printed = false;

    for (int i = 0; i < n; i++) {
        int child1_ind = 2*i + 1;
        int child2_ind = 2*i + 2;

        if (child1_ind < n && arr[child1_ind] > arr[i]) {
            cout << false;
            printed = true;
            break;
        }

        if (child2_ind < n && arr[child2_ind] > arr[i]) {
            cout << false;
            printed = true;
            break;
        }
    }

    if (!printed) {
        cout << true;
    }
}