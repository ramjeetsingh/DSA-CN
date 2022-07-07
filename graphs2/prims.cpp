#include <iostream>
using namespace std;

void prims(int **matrix, int v, int e, int* &parent, bool* &visited, int* &weight) {
    for (int i = 0; i < v; i++) {
        int min_wt_of = 0;
        int min_wt = INT_MAX;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (weight[i] < min_wt) {
                    min_wt = weight[i];
                    min_wt_of = i;
                }
            }
        }

        visited[min_wt_of] = true;

        for (int i = 0; i < v; i++) {
            if (matrix[min_wt_of][i] != 0) {
                if (!visited[i]) {
                    if (matrix[min_wt_of][i] < weight[i]) {
                        weight[i] = matrix[min_wt_of][i];
                        parent[i] = min_wt_of;
                    }
                }
            }
        }
    }
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
        int w;
        cin >> f >> s >> w;

        matrix[f][s] = w;
        matrix[s][f] = w;
    }

    int* parent = new int[v];
    bool* visited = new bool[v];
    int* weights = new int[v];

    for (int i = 0; i < v; i++) {
        parent[i] = -1;
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    weights[0] = 0;

    prims(matrix, v, e, parent, visited, weights);

    for (int i = 0; i < v; i++) {
        if (parent[i] != -1) {
            if (parent[i] > i) {
                cout << i << " " << parent[i] << " " << weights[i] << endl;
            } else {
                cout << parent[i] << " " << i << " " << weights[i] << endl;
            }
            
        }
    }

}