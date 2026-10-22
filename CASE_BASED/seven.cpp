#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, cost;
};

bool compare(Edge a, Edge b)
{
    return a.cost < b.cost;
}

int findParent(vector<int>& parent, int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}


void unionSet(vector<int>& parent, vector<int>& rank,
              int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u != v)
    {
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int main()
{
    int V, E;

    cout << "Enter number of stations: ";
    cin >> V;

    cout << "Enter number of maintenance links: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "\nEnter links as: Station1 Station2 MaintenanceCost\n";

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].cost;
    }

    
    sort(edges.begin(), edges.end(), compare);

    cout << "\n===== SORTED EDGE LIST =====\n";

    for (auto edge : edges)
    {
        cout << edge.u << " - "
             << edge.v << " : "
             << edge.cost << endl;
    }

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int selected = 0;

    cout << "\n===== KRUSKAL'S ALGORITHM =====\n";

    // Step 2: Select minimum-cost edges
    for (auto edge : edges)
    {
        int u = findParent(parent, edge.u);
        int v = findParent(parent, edge.v);

        if (u != v)
        {
            cout << "Selected Edge: "
                 << edge.u << " - "
                 << edge.v
                 << " (Cost = "
                 << edge.cost << ")" << endl;

            unionSet(parent, rank, u, v);

            totalCost += edge.cost;
            selected++;
        }
        else
        {
            cout << "Rejected Edge: "
                 << edge.u << " - "
                 << edge.v
                 << " (Cycle detected)" << endl;
        }

        // MST has V-1 edges
        if (selected == V - 1)
            break;
    }

    cout << "\n===== RESULT =====\n";

    cout << "Total Minimum Maintenance Cost = "
         << totalCost << endl;

    return 0;
}