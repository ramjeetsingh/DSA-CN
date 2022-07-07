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


bool print(int **matrix, int n, int sv, bool *visited, int v1, int v2) {
    visited[sv] = true;

    if (sv == v2) {
        cout << sv << " ";
        return true;
    }

    for (int i = 0; i < n; i++) {
        if (i == sv) {
            continue;
        }
        else {
            if (!visited[i]) {
                if (matrix[sv][i] == 1) {
                    bool ifPresent = print(matrix, n, i, visited, v1, v2);

                    if (ifPresent) {
                        cout << sv << " ";
                        return true;
                    }
                }
                
            }
        }
    }
    return false;
}

void DFS(int **matrix, int n, int v1, int v2) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    print(matrix, n, v1, visited, v1, v2);
    
    delete[] visited;
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

    bool hasPath = checkPath(matrix, v, v1, v2, visited);
    if (!hasPath) {
        cout << " ";
    }
    else {
        DFS(matrix, v, v1, v2);
    }

}