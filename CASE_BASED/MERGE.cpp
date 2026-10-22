#include <iostream>
using namespace std;


void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    int temp[100];

    
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }


    for (i = low, k = 0; i <= high; i++, k++)
    {
        arr[i] = temp[k];
    }

    
    cout << "Merged: ";
    for (i = low; i <= high; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        
        cout << "Divide: ";
        for (int i = low; i <= high; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;

    cout << "Enter number of customer order IDs: ";
    cin >> n;

    int arr[100];

    cout << "Enter order IDs:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n--- Merge Sort Trace ---\n";
    mergeSort(arr, 0, n - 1);

    cout << "\nSorted Customer Order IDs: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}