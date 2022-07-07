#include <iostream>
#include <queue>
using namespace std;

void print(int **matrix, int n, bool *visited, queue<int> pending) {
    int front = pending.front();
    if (!visited[front]) {
        cout << front <<  " ";
        visited[front] = true;
    }
    
    pending.pop();

    for (int i = 0; i < n; i++) {
        if (i == front) {
            continue;
        } else {
            if (!visited[i]) {
                if (matrix[front][i] == 1) {
                    pending.push(i);
                }
            }
        }
    }
    if (pending.size() == 0) {
        return;
    }
    print(matrix, n, visited, pending);
}

void BFS(int **matrix, int n) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    queue<int> pending;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            pending.push(i);
            print(matrix, n, visited, pending);
        }
    }
}



int main() {
    int n;
    int e;
    cin >> n >> e;

    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
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
  
    BFS(matrix, n);
}