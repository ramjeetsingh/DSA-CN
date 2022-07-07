#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void print(int **matrix, int n, int sv, bool *visited, vector<int> &comp) {
    comp.push_back(sv);
    visited[sv] = true;

    for (int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        else {
            if (!visited[i]) {
                if (matrix[sv][i] == 1) {
                    print(matrix, n, i, visited, comp);
                }
            }
        }
    }
}

vector<vector<int>> DFS(int **matrix, int n) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    vector<vector<int>> output;

    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            print(matrix, n, i, visited, component);
            output.push_back(component);
        }
    }

    return output;
    
    delete[] visited;
}



int main() {
    int n, e;
    cin >> n >> e;

    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;

        matrix[f][s] = 1;
        matrix[s][f] = 1;
    }

    vector<vector<int>> ans = DFS(matrix, n);

    for (int i = 0; i < ans.size(); i++) {
        sort(ans[i].begin(), ans[i].end());
        
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}