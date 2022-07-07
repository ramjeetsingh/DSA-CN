#include <iostream>
#include <cmath>
using namespace std;

int knapSackDP(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[2][W + 1];
    // We know we are always using the current row or
    // the previous row of the array/vector . Thereby we can
    // improve it further by using a 2D array but with only
    // 2 rows i%2 will be giving the index inside the bounds
    // of 2d array K
 
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i % 2][w] = 0;
            else if (wt[i - 1] <= w)
                K[i % 2][w] = max(
                    val[i - 1]
                        + K[(i - 1) % 2][w - wt[i - 1]],
                    K[(i - 1) % 2][w]);
            else
                K[i % 2][w] = K[(i - 1) % 2][w];
        }
    }
    return K[n % 2][W];
}


int knapsack(int *wts, int* val, int n, int i, int w) {
    if (i == n) {
        return 0;
    }

    if (w <= 0) {
        return 0;
    }

    int not_including = knapsack(wts, val, n, i+1, w);

    int including = INT_MIN;
    if (w >= wts[i]) {
        including = val[i] + knapsack(wts, val, n, i+1, w - wts[i]);
    } 

    return max(including, not_including);
}


int main() {
    int n;
    cin >> n;

    int *wts = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> wts[i];
    }

    int *val = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    int w;
    cin >> w;

    cout << knapsack(wts, val, n, 0, w);
}