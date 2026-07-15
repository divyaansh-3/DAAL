#include <stdio.h>

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pivot = a[low];   // first element as pivot
        int i = low + 1;
        int j = high;
        int temp;

        // Partitioning
        while (i <= j) {
            while (i <= high && a[i] <= pivot)
                i++;

            while (a[j] > pivot)
                j--;

            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        // Place pivot in correct position
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        // Recursive calls
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}