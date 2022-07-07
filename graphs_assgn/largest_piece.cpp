#include <iostream>
#include <vector>
using namespace std;


void check(vector<string> matrix, vector<vector<bool>> &visited, int row, int col, int n, int m, int &num) {
    visited[row][col] = true;

    if (row != 0) {                                 //upper
        if (matrix[row-1][col] == '1') {
            if (!visited[row-1][col]) {
                num++;
                check(matrix, visited, row-1, col, n, m, num);
            }
        }
    }


    if (col != m-1) {                               //right
        if (matrix[row][col+1] == '1') {
            if (!visited[row][col+1]) {
                num++;
                check(matrix, visited, row, col+1, n, m, num);
            }
        }
    }


    if (row != n-1) {                                  //lower
        if (matrix[row+1][col] == '1') {
            if (!visited[row+1][col]) {
                num++;
                check(matrix, visited, row+1, col, n, m, num);
            }
        }
    }



    if (col != 0) {                                      //left
        if (matrix[row][col-1] == '1') {
            if (!visited[row][col-1]) {
                num++;
                check(matrix, visited, row, col-1, n, m, num);
            }
        }
    }

    return;    
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<string> matrix;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;

        matrix.push_back(row);
    }

    vector<vector<bool>> visited;
    for (int i = 0; i < n; i++) {
        vector<bool> row;
        for (int j = 0; j < m; j++) {
            row.push_back(false);
        }

        visited.push_back(row);
    }

    vector<vector<bool>> orig_visited = visited;

    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') {
                int num = 1;

                check(matrix, visited, i, j, n, m, num);
                
                visited = orig_visited;
                
                if (num > ans) {
                    ans = num;
                }
            }
        }
    }
    cout << ans;
}