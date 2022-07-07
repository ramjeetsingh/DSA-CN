#include <iostream>
#include <queue>
#include <unordered_map>
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


void print(int **matrix, int n, bool *visited, queue<int> pending, int v1, int v2, unordered_map<int, int> map) {
    int front = pending.front();
    visited[front] = true;
    pending.pop();


    if (front == v2) {
        int node = front;

        while (node != v1) {
            cout << node << ' ';
            node = map[node];
        }
        cout << node;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i == front) {
            continue;
        } else {
            if (!visited[i]) {
                if (matrix[front][i] == 1) {
                    pending.push(i);
                    if (map.find(i) == map.end()) {
                        map[i] = front;
                    }
                }
            }
        }
    }
    if (pending.size() == 0) {
        return;
    }
    print(matrix, n, visited, pending, v1, v2, map);
    return;
}

void BFS(int **matrix, int n, int v1, int v2) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    queue<int> pending;

    unordered_map<int, int> map; 
    
    pending.push(v1);
    print(matrix, n, visited, pending, v1, v2, map);

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
        cout << "No Path";
    }
    else {
        BFS(matrix, v, v1, v2);
    }

}