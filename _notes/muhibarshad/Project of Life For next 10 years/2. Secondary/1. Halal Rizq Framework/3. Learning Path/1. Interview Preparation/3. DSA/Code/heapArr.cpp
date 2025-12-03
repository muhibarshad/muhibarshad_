#include <iostream>
using namespace std;

class MaxHeap
{
    int *heap;
    int capacity;
    int size;

public:
    MaxHeap(int cap)
    {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap is full!\n";
            return;
        }
        size++;
        int i = size - 1;
        heap[i] = val;

        // Heapify up (Bubble Up)
        while (i != 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    int extractMax()
    {
        if (size <= 0)
            return -1;
        if (size == 1)
        {
            size--;
            return heap[0];
        }

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return root;
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    ~MaxHeap()
    {
        delete[] heap;
    }
};

int main()
{
    MaxHeap h(10);
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(60);

    cout << "Heap elements: ";
    h.printHeap();

    cout << "Extracted max: " << h.extractMax() << endl;

    cout << "Heap after extraction: ";
    h.printHeap();

    return 0;
}
