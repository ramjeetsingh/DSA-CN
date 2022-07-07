#include <iostream>
#include <vector>
using namespace std;


bool check(vector<string> matrix, vector<vector<bool>> visited, char color, int start_row, int start_col, int row, int col, int n, int m, int &num) {
    visited[row][col] = true;

    if ((row == start_row && (col == start_col-1 || col == start_col+1)) || (col == start_col && (row == start_row-1 || row == start_row+1))) {
        if (num >= 4) {
            return true;
        }
    }


    if (row != 0) {                                 //upper
        if (matrix[row-1][col] == color) {
            if (!visited[row-1][col]) {
                num++;
                bool smallAns = check(matrix, visited, color, start_row, start_col, row-1, col, n, m, num);
                if (smallAns) {
                    return true;
                } else {
                    num--;
                }
            }
        }
    }


    if (col != m-1) {                               //right
        if (matrix[row][col+1] == color) {
            if (!visited[row][col+1]) {
                num++;
                bool smallAns = check(matrix, visited, color, start_row, start_col, row, col+1, n, m, num);
                if (smallAns) {
                    return true;
                } else {
                    num--;
                }
            }
        }
    }


    if (row != n-1) {                                  //lower
        if (matrix[row+1][col] == color) {
            if (!visited[row+1][col]) {
                num++;
                bool smallAns = check(matrix, visited, color, start_row, start_col, row+1, col, n, m, num);
                if (smallAns) {
                    return true;
                } else {
                    num--;
                }
            }
        }
    }



    if (col != 0) {                                      //left
        if (matrix[row][col-1] == color) {
            if (!visited[row][col-1]) {
                num++;
                bool smallAns = check(matrix, visited, color, start_row, start_col, row, col-1, n, m, num);
                if (smallAns) {
                    return true;
                } else {
                    num--;
                }
            }
        }
    }

    return false;    
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                int num = 1;

                bool res = check(matrix, visited, matrix[i][j], i, j, i, j, n, m, num);
                if (res) {
                    if (num >= 4) {
                        cout << true;
                        return 0;
                    }
                } else {
                    continue;
                }
            }
        }
    }
    cout << false;
}