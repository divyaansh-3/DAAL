
#include <iostream>
using namespace std;

#define MAX 20

int graph[MAX][MAX];
int path[MAX];
int n;
int countCycles = 0;

void printCycle()
{
    for (int i = 0; i < n; i++)
        cout << path[i] << " ";

    cout << path[0] << endl;
    countCycles++;
}

bool isSafe(int vertex, int pos)
{
    
    if (graph[path[pos - 1]][vertex] == 0)
        return false;

    for (int i = 0; i < pos; i++)
    {
        if (path[i] == vertex)
            return false;
    }

    return true;
}

void hamiltonianCycle(int pos)
{
    
    if (pos == n)
    {
        
        if (graph[path[n - 1]][path[0]] == 1)
            printCycle();

        return;
    }

    
    for (int v = 1; v < n; v++)
    {
        if (isSafe(v, pos))
        {
            path[pos] = v;

            hamiltonianCycle(pos + 1);

            
            path[pos] = -1;
        }
    }
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    cout << "\nHamiltonian cycles:\n";

    hamiltonianCycle(1);

    if (countCycles == 0)
        cout << "No Hamiltonian cycle exists.\n";
    else
        cout << "Total cycles = " << countCycles << endl;

    return 0;
}
