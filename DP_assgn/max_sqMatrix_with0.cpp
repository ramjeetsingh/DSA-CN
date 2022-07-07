#include <iostream>
#include <vector>
using namespace std;

int side(vector<vector<int>> matrix, int n, int m) {
    int **ans = new int*[n];
    for (int i = 0; i < n; i++) {
        ans[i] = new int[m];
    }

    for (int row = 0; row < n; row++) {
        ans[row][0] = 1^matrix[row][0];
    }
    for (int col = 0; col < m; col++) {
        ans[0][col] = 1^matrix[0][col];
    }

    for (int row = 1; row < n; row++) {
        for (int col = 1; col < m; col++) {
            if (matrix[row][col] == 1) {
                ans[row][col] = 0;
            }
            else {
                int diag = ans[row-1][col-1];
                int upper = ans[row-1][col];
                int left = ans[row][col-1];

                ans[row][col] = 1 + min(diag, min(upper, left));
            }
        }
    }

    int res = INT_MIN;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (ans[row][col] > res) {
                res = ans[row][col];
            } 
        }
    } 
    return res;
}



int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++) {
        vector<int> col;
        for (int j = 0; j < m; j++) {
            int ele;
            cin >> ele;

            col.push_back(ele);
        }

        matrix.push_back(col);
    }

    cout << side(matrix, n, m);
}