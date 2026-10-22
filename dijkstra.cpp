#include <iostream>
using namespace std;

#define INF 99999

void initializeGraph(int graph[][100], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = INF;
        }
    }
}

bool inputEdges(int graph[][100], int V, int E) {
    for (int i = 0; i < E; i++) {
        int u, v, w;

        cout << "Enter edge " << i + 1
             << " (source destination weight): ";
        cin >> u >> v >> w;

        if (u < 0 || u >= V || v < 0 || v >= V) {
            cout << "Invalid vertex number.\n";
            return false;
        }

        if (w < 0) {
            cout << "Negative edge weight is not allowed in Dijkstra's Algorithm.\n";
            return false;
        }

        graph[u][v] = w;
        graph[v][u] = w;
    }

    return true;
}

int findMinVertex(int dist[], bool visited[], int V) {
    int minDistance = INF;
    int minVertex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < minDistance) {
            minDistance = dist[i];
            minVertex = i;
        }
    }

    return minVertex;
}

void printDistanceTable(int dist[], int V, int iteration) {
    cout << "Iteration " << iteration << ": ";

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    cout << endl;
}

void dijkstra(int graph[][100], int V, int source,
              int dist[], int parent[]) {

    bool visited[100] = {false};

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    cout << "\nIntermediate Distance Table:\n";

    cout << "Initial: ";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;

    for (int count = 0; count < V; count++) {

        int u = findMinVertex(dist, visited, V);

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < V; v++) {

            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }

        printDistanceTable(dist, V, count + 1);
    }
}

void printShortestDistances(int dist[], int V, int source) {
    cout << "\nShortest Distances:\n";

    for (int i = 0; i < V; i++) {
        cout << source << " -> " << i << " = ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

void printShortestPathTree(int parent[], int V, int source) {
    cout << "\nShortest Path Tree:\n";

    for (int i = 0; i < V; i++) {
        if (i != source && parent[i] != -1) {
            cout << parent[i] << " -> " << i << endl;
        }
    }
}

int main() {

    int V, E;
    int graph[100][100];

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    initializeGraph(graph, V);

    cout << "\nEnter edges:\n";

    if (!inputEdges(graph, V, E)) {
        return 0;
    }

    int source;

    cout << "\nEnter source vertex: ";
    cin >> source;

    if (source < 0 || source >= V) {
        cout << "Invalid source vertex.\n";
        return 0;
    }

    int dist[100];
    int parent[100];

    dijkstra(graph, V, source, dist, parent);

    printShortestDistances(dist, V, source);

    printShortestPathTree(parent, V, source);

    return 0;
}