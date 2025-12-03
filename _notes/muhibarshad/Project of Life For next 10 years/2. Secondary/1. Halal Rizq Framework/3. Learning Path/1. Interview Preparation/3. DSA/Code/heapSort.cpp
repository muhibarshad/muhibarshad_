#include <iostream>
using namespace std;
/*
Heap Sort Process (Brief Notes):

Build Max-Heap: Start from the last non-leaf node and heapify each node → ensures largest element at root.

Swap Max with Last: Swap the root (max element) with the last element of the heap.

Reduce Heap Size: Exclude the last element (already in correct position) and heapify the remaining heap → restore max-heap.

Repeat: Continue swapping the new root with the last element of the reduced heap and heapify → gradually place second, third… largest elements at the end.

Result: After all iterations, the array becomes sorted in ascending order.

Key Points:

Heapify ensures max-heap property.

Each iteration moves the current largest element to its correct final position.

Time Complexity → O(n log n), Space Complexity → O(1) (in-place).
Time Complexity → O(n log n), Space Complexity → O(1) (in-place).
*/
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]); // Swap and continue heapifying
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // Heapify reduced heap
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {50, 30, 40, 10, 20, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
