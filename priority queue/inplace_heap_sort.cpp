#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    for (int i = 1; i < n; i++) {
        int childInd = i;

        while (childInd > 0) {
            int parentInd = (childInd-1)/2;

            if (arr[childInd] < arr[parentInd]) {
                int temp = arr[childInd];
                arr[childInd] = arr[parentInd];
                arr[parentInd] = temp;
            } else {
                break;
            }

            childInd = parentInd;
        }
    }


    //deleting elements

    int size = n;

    while (size > 1) {
        int temp = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = temp;

        size--;

        int parent_ind = 0;
        int left_child_ind = 2*parent_ind + 1;
        int right_child_ind = 2*parent_ind + 2;

        while (left_child_ind < size) {
            int minInd = parent_ind;

            if (arr[left_child_ind] < arr[minInd]) {
                minInd = left_child_ind;
            }

            if (right_child_ind < size && arr[right_child_ind] < arr[minInd]) {
                minInd = right_child_ind;
            }

            if (minInd == parent_ind) {
                break;
            }

            int temp = arr[minInd];
            arr[minInd] = arr[parent_ind];
            arr[parent_ind] = temp;

            parent_ind = minInd;
            left_child_ind = 2*parent_ind + 1;
            right_child_ind = 2*parent_ind + 2;
        }
    }
    for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";  
    }
}