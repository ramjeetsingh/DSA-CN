#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class edge {
    public :
        int src;
        int dest;
        int wgt;

        edge() = default;

        edge(int a, int b, int w){
            this->src = a;
            this->dest = b;
            this->wgt = w;
        }
};

int parent(int v, int parents[]) {
    // int ans = parents[v];

    // while (ans != v) {
    //     v = ans;
    //     ans = parents[v];
    // }

    // return ans;

    if (v == parents[v]) {
        return v;
    }

    return parent(parents[v], parents);
}


edge* kruskals(vector<edge> edges, int v, int e) {
    int* parents = new int[v];
    for (int i = 0; i < v; i++) {
        parents[i] = i;
    }

    edge* output = new edge[v-1];

    int count = 0;
    int i = 0;
    while (count < v-1) {
        edge topEdge = edges[i];

        if (parent(topEdge.src, parents) != parent(topEdge.dest, parents)) {
            output[count] = topEdge;
            parents[parent(topEdge.src, parents)] = parent(topEdge.dest, parents);
            count++; 
        }
        i++;
    }

    return output;
}


int main() {
    int v, e;
    cin >> v >> e;

    vector<edge> edges;
    for (int i = 0; i < e; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        edge e(v1, v2, w);

        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), [](const edge& a, const edge& b) {
        return a.wgt < b.wgt;
    });

    edge* output = kruskals(edges, v, e);
    for (int i = 0; i < v-1; i++) {
        edge e = output[i];
        if (e.src < e.dest) {
            cout << e.src << " " << e.dest << " " << e.wgt << endl;
        } else {
            cout << e.dest << " " << e.src << " " << e.wgt << endl;
        }
        
    }
}