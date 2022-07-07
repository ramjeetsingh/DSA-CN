#include <iostream>
using namespace std;

int partition(int input[], int start, int end)
{
    int pivot = input[end]; 
    int i = start - 1;      // Index of smaller element and indicates the right position of pivot found so far

    for (int j = start; j <= end - 1; j++)
    {
        // If current element is smaller than the pivot
        if (input[j] < pivot)
        {
            i++;
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
        }
    }
    int temp = input[i + 1];
    input[i + 1] = input[end];
    input[end] = temp;
    return (i + 1);
}


void quickSort(int input[], int start, int end)
{
    if (start >= end)
        return;
    else
    {
        int index = partition(input, start, end);
        quickSort(input, start, index - 1);
        quickSort(input, index + 1, end);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);
    for (int i = 0; i <n; i++) {
        cout << arr[i] << ' ';
    }
}