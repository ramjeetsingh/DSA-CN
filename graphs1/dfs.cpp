#include <iostream>
using namespace std;

void print(int **matrix, int n, int sv, bool *visited) {
    cout << sv << " ";
    visited[sv] = true;

    for (int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        else {
            if (!visited[i]) {
                if (matrix[sv][i] == 1) {
                    print(matrix, n, i, visited);
                }
            }
        }
    }
}

void DFS(int **matrix, int n) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            print(matrix, n, i, visited);
        }
    }
    
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

    DFS(matrix, n);
}