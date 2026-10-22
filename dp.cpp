#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

int n;
vector<vector<int>> dist;
vector<vector<int>> dp;
vector<vector<int>> parent;

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city))) {
            int cost = dist[pos][city] + tsp(mask | (1 << city), city);

            if (cost < ans) {
                ans = cost;
                parent[mask][pos] = city;
            }
        }
    }

    dp[mask][pos] = ans;
    return ans;
}

void displayStates() {
    cout << "\nIntermediate DP States:\n";

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int pos = 0; pos < n; pos++) {
            if (dp[mask][pos] != -1) {
                cout << "Visited { ";
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i))
                        cout << i << " ";
                }
                cout << "} Current City " << pos
                     << " -> Minimum Cost = " << dp[mask][pos] << endl;
            }
        }
    }
}

void displayPath() {
    int mask = 1;
    int pos = 0;

    cout << "\nOptimal Path: 0";

    while (true) {
        int next = parent[mask][pos];

        if (next == -1)
            break;

        cout << " -> " << next;
        mask |= (1 << next);
        pos = next;
    }

    cout << " -> 0\n";
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    dist.resize(n, vector<int>(n));

    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    int totalMasks = 1 << n;

    dp.assign(totalMasks, vector<int>(n, -1));
    parent.assign(totalMasks, vector<int>(n, -1));

    int minimumCost = tsp(1, 0);

    displayStates();

    cout << "\nMinimum Travelling Cost = " << minimumCost << endl;

    displayPath();

    cout << "\nTime Complexity:\n";
    cout << "Best Case    : O(n^2 * 2^n)\n";
    cout << "Average Case : O(n^2 * 2^n)\n";
    cout << "Worst Case   : O(n^2 * 2^n)\n";

    cout << "\nSpace Complexity: O(n * 2^n)\n";

    return 0;
}