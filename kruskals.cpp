#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 50

struct Edge {
    int u, v, weight;
};


bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}


int findParent(int parent[], int vertex) {
    if (parent[vertex] == vertex)
        return vertex;

    return parent[vertex] = findParent(parent, parent[vertex]);
}


void unionSet(int parent[], int rank[], int u, int v) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v) {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main() {
    int n, e;
    Edge edges[MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < e; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    
    sort(edges, edges + e, compare);

    int parent[MAX];
    int rank[MAX] = {0};

    
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0;
    int selectedEdges = 0;

    cout << "\nEdges selected by Kruskal's Algorithm:\n";

    for (int i = 0; i < e && selectedEdges < n - 1; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        
        if (findParent(parent, u) != findParent(parent, v)) {

            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSet(parent, rank, u, v);

            selectedEdges++;
        }
    }

    if (selectedEdges != n - 1) {
        cout << "\nMST cannot be formed.\n";
    }
    else {
        cout << "\nTotal Minimum Cost = "
             << totalCost << endl;
    }

    return 0;
}