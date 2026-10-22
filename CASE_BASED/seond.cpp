#include <iostream>
using namespace std;

// ---------------- MERGE SORT ----------------

void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];

    // Display merge step
    cout << "Merged: ";
    for (i = low; i <= high; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        cout << "Divide: ";
        for (int i = low; i <= high; i++)
            cout << arr[i] << " ";
        cout << endl;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// ---------------- QUICK SORT ----------------

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// ---------------- MAIN ----------------

int main()
{
    int n;

    cout << "Enter number of transaction timestamps: ";
    cin >> n;

    int arr[100], mergeArr[100], quickArr[100];

    cout << "Enter transaction timestamps:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mergeArr[i] = arr[i];
        quickArr[i] = arr[i];
    }

    // Merge Sort
    cout << "\n===== MERGE SORT =====\n";

    mergeSort(mergeArr, 0, n - 1);

    cout << "Final Sorted Data: ";
    for (int i = 0; i < n; i++)
        cout << mergeArr[i] << " ";

    // Quick Sort
    cout << "\n\n===== QUICK SORT =====\n";

    quickSort(quickArr, 0, n - 1);

    cout << "Final Sorted Data: ";
    for (int i = 0; i < n; i++)
        cout << quickArr[i] << " ";

    cout << "\n\n===== COMPLEXITY COMPARISON =====\n";

    cout << "Merge Sort:\n";
    cout << "Best Case    : O(n log n)\n";
    cout << "Average Case : O(n log n)\n";
    cout << "Worst Case   : O(n log n)\n";

    cout << "\nQuick Sort:\n";
    cout << "Best Case    : O(n log n)\n";
    cout << "Average Case : O(n log n)\n";
    cout << "Worst Case   : O(n^2)\n";

    return 0;
}