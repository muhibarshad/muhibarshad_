#include <iostream>
using namespace std;

// Merge Sort – Divide and merge
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        quickSort(arr, left, mid);
        quickSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Shell Sort – Gapped insertion sort
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Quick Sort – Pivot-based sorting
int partition(int arr[], int low, int high)
{
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    // Merge Sort
    quickSort(arr, 0, n - 1);
    cout << "Merge Sorted: ";
    printArray(arr, n);

    // Shell Sort
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    shellSort(arr2, n);
    cout << "Shell Sorted: ";
    printArray(arr2, n);

    // Quick Sort
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr3, 0, n - 1);
    cout << "Quick Sorted: ";
    printArray(arr3, n);

    return 0;
}
