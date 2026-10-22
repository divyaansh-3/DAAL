#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include<algorithm>
using namespace std;

const int INF = 1000000000;


int tsp(int n, const vector<vector<int>>& dist,
        vector<vector<int>>& dp, vector<vector<int>>& parent) {

    int totalMasks = 1 << n;

    
    dp[1][0] = 0;

    
    for (int mask = 1; mask < totalMasks; mask++) {

        for (int current = 0; current < n; current++) {

            
            if (!(mask & (1 << current)))
                continue;

            
            if (current == 0 && mask != 1)
                continue;

            // Try coming to current city from every previous city
            for (int previous = 0; previous < n; previous++) {

                if (previous == current)
                    continue;

                if (!(mask & (1 << previous)))
                    continue;

                if (dp[mask ^ (1 << current)][previous] == INF)
                    continue;

                int newCost =
                    dp[mask ^ (1 << current)][previous]
                    + dist[previous][current];

                if (newCost < dp[mask][current]) {
                    dp[mask][current] = newCost;
                    parent[mask][current] = previous;
                }
            }
        }
    }

    // All cities visited
    int finalMask = totalMasks - 1;

    int minimumCost = INF;
    int lastCity = -1;

    // Return from last city to starting city
    for (int city = 1; city < n; city++) {

        int totalCost = dp[finalMask][city] + dist[city][0];

        cout << "Return from City " << city
             << " to City 0: "
             << dp[finalMask][city] << " + "
             << dist[city][0] << " = "
             << totalCost << endl;

        if (totalCost < minimumCost) {
            minimumCost = totalCost;
            lastCity = city;
        }
    }

  
    vector<int> path;

    int mask = finalMask;
    int current = lastCity;

    while (current != -1) {
        path.push_back(current);

        int previous = parent[mask][current];

        mask = mask ^ (1 << current);
        current = previous;
    }

    path.push_back(0);

    // Reverse path
    reverse(path.begin(), path.end());

    cout << "\nOptimal Path: ";

    for (int city : path)
        cout << city << " -> ";

    cout << "0" << endl;

    return minimumCost;
}


// Function to display DP table
void displayDP(int n, const vector<vector<int>>& dp) {

    int totalMasks = 1 << n;

    cout << "\n========== INTERMEDIATE DP STATES ==========\n";

    for (int mask = 1; mask < totalMasks; mask++) {

        cout << "Set { ";

        for (int city = 0; city < n; city++) {
            if (mask & (1 << city))
                cout << city << " ";
        }

        cout << "} : ";

        for (int city = 0; city < n; city++) {

            if (dp[mask][city] == INF)
                cout << "City " << city << " = INF  ";
            else
                cout << "City " << city << " = "
                     << dp[mask][city] << "  ";
        }

        cout << endl;
    }
}



void displayMatrix(int n, const vector<vector<int>>& dist) {

    cout << "\n========== DISTANCE MATRIX ==========\n";

    cout << setw(6) << " ";

    for (int i = 0; i < n; i++)
        cout << setw(6) << i;

    cout << endl;

    for (int i = 0; i < n; i++) {

        cout << setw(6) << i;

        for (int j = 0; j < n; j++)
            cout << setw(6) << dist[i][j];

        cout << endl;
    }
}



int main() {

    int n;

    cout << "Enter number of cities: ";
    cin >> n;

    if (n < 2) {
        cout << "At least 2 cities are required." << endl;
        return 0;
    }

    vector<vector<int>> dist(n, vector<int>(n));

    cout << "\nEnter the distance matrix:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cin >> dist[i][j];

            if (dist[i][j] < 0) {
                cout << "Distance cannot be negative." << endl;
                return 0;
            }
        }
    }

    displayMatrix(n, dist);

    int totalMasks = 1 << n;

    vector<vector<int>> dp(
        totalMasks,
        vector<int>(n, INF)
    );

    vector<vector<int>> parent(
        totalMasks,
        vector<int>(n, -1)
    );

    int minimumCost = tsp(n, dist, dp, parent);

    displayDP(n, dp);

    cout << "\n========== FINAL RESULT ==========\n";

    cout << "Minimum Travelling Cost = "
         << minimumCost << endl;

    cout << "Starting City = 0" << endl;

    return 0;
}