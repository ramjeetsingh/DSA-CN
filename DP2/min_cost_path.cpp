#include <iostream>
#include <vector>
using namespace std;

int minCostDP(vector<vector<int>> cost, int n, int m) {
    vector<vector<int>> output;

    output[m-1][n-1] = cost[m-1][n-1];

    for (int col = n-2; col >= 0; col--) {
        output[m-1][col] = cost[m-1][col] + output[m-1][col+1];
    }

    for (int row = m-2; row >= 0; row--) {
        output[row][n-1] = cost[row][n-1] + output[row+1][n-1];
    }

    for (int row = m-2; row >= 0; row--) {
        for (int col = n-2; col>=0; col--) {
            output[row][col] = cost[row][col] + min(output[row+1][col+1], min(output[row][col+1], output[row+1][col]));
        }
    }

    return output[0][0];
}



int minCost(vector<vector<int>> cost, int n, int m, int current_row, int current_col) {
    if (current_col == n-1 && current_row == m-1) {
        return cost[current_row][current_col];
    }

    int cost_from_right = INT_MAX;
    if (current_col != n-1) {
        cost_from_right = minCost(cost, n, m, current_row, current_col+1);
    }

    int cost_from_down = INT_MAX;
    if (current_row != m-1) {
        cost_from_down = minCost(cost, n, m, current_row+1, current_col);
    }
    
    int cost_from_diag = INT_MAX;
    if (current_row != m-1 && current_col != n-1) {
        cost_from_diag = minCost(cost, n, m, current_row+1, current_col+1);
    }

    int min_path = min(cost_from_diag, min(cost_from_down, cost_from_right));

    return min_path + cost[current_row][current_col];
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> cost;

    for (int i = 0; i < m; i++) {
        vector<int> column;
        for (int j = 0; j < n; j++) {
            int e;
            cin >> e;

            column.push_back(e);
        }

        cost.push_back(column);
    }

    cout << minCost(cost, n, m, 0, 0);
}