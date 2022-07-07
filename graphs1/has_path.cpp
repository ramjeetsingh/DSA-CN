#include <iostream>
using namespace std;

bool checkPath(int **matrix, int v, int v1, int v2, bool *visited) {
    visited[v1] = true;

    if (matrix[v1][v2] == 1) {
        return true;
    }


    for (int i = 0; i < v; i++) {
        if (i == v1) {
            continue;
        }

        if (matrix[v1][i] == 1) {
            if (!visited[i]) {
                bool smallRes = checkPath(matrix, v, i, v2, visited);
                if (smallRes == true) {
                    return true;
                }
            }
        }
    }

    return false;
}


int main() {
    int v, e;
    cin >> v >> e;

    int **matrix = new int*[v];
    for (int i = 0; i < v; i++) {
        matrix[i] = new int[v];
        for (int j = 0; j < v; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int f;
        int s;
        cin >> f >> s;

        matrix[f][s] = 1;
        matrix[s][f] = 1;
    }

    int v1, v2;
    cin >> v1 >> v2;

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }

    cout << checkPath(matrix, v, v1, v2, visited);
}