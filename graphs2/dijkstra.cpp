#include <iostream>
using namespace std;

void dijkstra(int **matrix, int v, int e, bool* &visited, int* &cost) {
    for (int i = 0; i < v; i++) {
        int min_wt_of = 0;
        int min_wt = INT_MAX;
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (cost[i] < min_wt) {
                    min_wt = cost[i];
                    min_wt_of = i;
                }
            }
        }

        visited[min_wt_of] = true;

        for (int i = 0; i < v; i++) {
            if (matrix[min_wt_of][i] != 0) {
                if (!visited[i]) {
                    int cost_from_this_path = cost[min_wt_of] + matrix[min_wt_of][i];
                    if(cost_from_this_path < cost[i]) {
                        cost[i] = cost_from_this_path;
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

    bool* visited = new bool[v];
    int* cost = new int[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        cost[i] = INT_MAX;
    }
    cost[0] = 0;

    dijkstra(matrix, v, e, visited, cost);

    for (int i = 0; i < v; i++) {
        cout << i << " " << cost[i] << endl;
    }
}