#include <iostream>
using namespace std;

void printArray(int arr[], int l, int r)
{
    for (int i = l; i <= r; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int l, int mid, int r)
{
    cout << "Merging: ";
    printArray(arr, l, mid);
    cout << "     and ";
    printArray(arr, mid + 1, r);

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[100], R[100];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    cout << "After Merge: ";
    printArray(arr, l, r);
    cout << endl;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        cout << "Dividing: ";
        printArray(arr, l, r);

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\n--- Merge Sort Trace ---\n\n";

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}