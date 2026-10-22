#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item
{
    int id;
    double profit;
    double weight;
    double ratio;
};

bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    double capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter profit and weight of each item:\n";

    for (int i = 0; i < n; i++)
    {
        items[i].id = i + 1;

        cout << "Item " << i + 1 << " profit: ";
        cin >> items[i].profit;

        cout << "Item " << i + 1 << " weight: ";
        cin >> items[i].weight;

        items[i].ratio = items[i].profit / items[i].weight;
    }

    cout << "\nEnter knapsack capacity: ";
    cin >> capacity;

    cout << "\nProfit-to-Weight Ratio:\n";
    cout << "Item\tProfit\tWeight\tRatio\n";

    for (int i = 0; i < n; i++)
    {
        cout << items[i].id << "\t"
             << items[i].profit << "\t"
             << items[i].weight << "\t"
             << fixed << setprecision(2)
             << items[i].ratio << endl;
    }

    sort(items.begin(), items.end(), compare);

    double totalProfit = 0;
    double remainingCapacity = capacity;

    cout << "\nItem Selection Sequence:\n";

    for (int i = 0; i < n; i++)
    {
        if (remainingCapacity == 0)
            break;

        if (items[i].weight <= remainingCapacity)
        {
            remainingCapacity -= items[i].weight;
            totalProfit += items[i].profit;

            cout << "Item " << items[i].id
                 << " -> 100% taken"
                 << " (Profit = " << items[i].profit << ")" << endl;
        }
        else
        {
            double fraction = remainingCapacity / items[i].weight;

            totalProfit += items[i].profit * fraction;

            cout << "Item " << items[i].id
                 << " -> " << fixed << setprecision(2)
                 << fraction * 100 << "% taken"
                 << " (Profit = "
                 << items[i].profit * fraction
                 << ")" << endl;

            remainingCapacity = 0;
        }
    }

    cout << "\nMaximum Profit = "
         << fixed << setprecision(2)
         << totalProfit << endl;

    cout << "\nTime Complexity:\n";
    cout << "Best Case: O(n log n)\n";
    cout << "Average Case: O(n log n)\n";
    cout << "Worst Case: O(n log n)\n";

    return 0;
}