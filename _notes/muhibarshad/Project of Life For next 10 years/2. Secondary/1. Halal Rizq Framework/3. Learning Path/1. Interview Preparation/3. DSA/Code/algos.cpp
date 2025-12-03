#include <iostream>
using namespace std;

// Linear Search – Sequential search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

// Binary Search – Divide and conquer search
int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Bubble Sort – Adjacent swapping
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Insertion Sort – Insert elements at the correct position
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort – Select minimum, place it first
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Searching
    int key = 12;
    cout << "Linear Search (key = 12): " << linearSearch(arr, n, key) << endl;

    // Sorting
    int sortedArr[] = {11, 12, 22, 25, 64}; // Binary Search requires sorted array
    cout << "Binary Search (key = 12): " << binarySearch(sortedArr, 0, n - 1, key) << endl;

    cout << "\nOriginal Array: ";
    printArray(arr, n);

    bubbleSort(arr, n);
    cout << "Bubble Sorted: ";
    printArray(arr, n);

    insertionSort(arr, n);
    cout << "Insertion Sorted: ";
    printArray(arr, n);

    selectionSort(arr, n);
    cout << "Selection Sorted: ";
    printArray(arr, n);

    return 0;
}
