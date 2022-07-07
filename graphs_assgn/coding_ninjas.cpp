#include <iostream>
#include <vector>
using namespace std;


bool check(vector<string> matrix, vector<vector<bool>> visited, string s, int index, int row, int col, int n, int m) {
    char letter = s[index];
    visited[row][col] = true;

    if (letter != 'A') {
        char next_letter = s[index+1];

        if (row != 0 && col != 0) {                      //upper left
            if (matrix[row-1][col-1] == next_letter) {
                if (!visited[row-1][col-1]) {
                    bool smallAns = check(matrix, visited, s, index+1, row-1, col-1, n, m);
                    if (smallAns) {
                        return true;
                    }
                }
            }
        }

        if (row != 0) {                                 //upper
            if (matrix[row-1][col] == next_letter) {
                if (!visited[row-1][col]) {
                    bool smallAns = check(matrix, visited, s, index+1, row-1, col, n, m);
                    if (smallAns) {
                        return true;
                    }
                }
            }
        }

        if (row != 0 && col != m-1) {                   //upper right
            if (matrix[row-1][col+1] == next_letter) {
                if (!visited[row-1][col+1]) {
                    bool smallAns = check(matrix, visited, s, index+1, row-1, col+1, n, m);
                    if (smallAns) {
                        return true;
                    }
                }
            }
        }

        if (col != m-1) {                               //right
            if (matrix[row][col+1] == next_letter) {
                if (!visited[row][col+1]) {
                    bool smallAns = check(matrix, visited, s, index+1, row, col+1, n, m);
                    if (smallAns) {
                        return true;
                    }
                }
            }
        }

        if (row != n-1 && col != m-1) {                     //lower right
            if (matrix[row+1][col+1] == next_letter) {
                if (!visited[row+1][col+1]) {
                    bool smallAns = check(matrix, visited, s, index+1, row+1, col+1, n, m);
                    if (smallAns) {
                        return true;
                    }
                }
            }
        }

        if (row != n-1) {                                  //lower
            if (matrix[row+1][col] == next_letter) {
                if (!visited[row+1][col]) {
                    bool smallAns = check(matrix, visited, s, index+1, row+1, col, n, m);
                    if (smallAns) {
                        return true;
                    }
                }
            }
        }

        if (row != n-1 && col != 0) {                       //lower left  
            if (matrix[row+1][col-1] == next_letter) {
                if (!visited[row+1][col-1]) {
                    bool smallAns = check(matrix, visited, s, index+1, row+1, col-1, n, m);
                    if (smallAns) {
                        return true;
                    }
                }
            }
        }


        if (col != 0) {                                      //left
            if (matrix[row][col-1] == next_letter) {
                if (!visited[row][col-1]) {
                    bool smallAns = check(matrix, visited, s, index+1, row, col-1, n, m);
                    if (smallAns) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
    else {
        return true;
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

    string s = "CODINGNINJA";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'C') {
                bool res = check(matrix, visited, s, 0, i, j, n, m);
                if (res) {
                    cout << true;
                    return 0;
                } else {
                    continue;
                }
            }
        }
    }
    cout << false;
}