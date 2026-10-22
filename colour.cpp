#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int vertex, int color, vector<vector<int>>& graph,
            vector<int>& colors, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && colors[i] == color)
            return false;
    }

    return true;
}

bool graphColoring(int vertex, int n, int m,
                   vector<vector<int>>& graph,
                   vector<int>& colors)
{
    if (vertex == n)
        return true;

    for (int color = 1; color <= m; color++)
    {
        if (isSafe(vertex, color, graph, colors, n))
        {
            colors[vertex] = color;

            if (graphColoring(vertex + 1, n, m, graph, colors))
                return true;

            colors[vertex] = 0;
        }
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    vector<int> colors(n, 0);

    int minColors = 1;

    while (true)
    {
        fill(colors.begin(), colors.end(), 0);

        if (graphColoring(0, n, minColors, graph, colors))
            break;

        minColors++;
    }

    cout << "\nMinimum number of colors required: "
         << minColors << endl;

    cout << "Valid color assignment:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i
             << " -> Color " << colors[i] << endl;
    }

    return 0;
}