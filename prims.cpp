#include <iostream>
using namespace std;

#define INF 9999
#define MAX 10

int main() {
    int n;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int edges = 0, totalCost = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the cost adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];

            
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    
    visited[0] = 1;

    cout << "\nEdges selected by Prim's Algorithm:\n";

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1 || v == -1) {
            cout << "MST cannot be formed.\n";
            return 0;
        }

        cout << u << " - " << v << " : " << min << endl;

        totalCost += min;
        visited[v] = 1;
        edges++;
    }

    cout << "\nTotal Minimum Cost = " << totalCost << endl;

    return 0;
}