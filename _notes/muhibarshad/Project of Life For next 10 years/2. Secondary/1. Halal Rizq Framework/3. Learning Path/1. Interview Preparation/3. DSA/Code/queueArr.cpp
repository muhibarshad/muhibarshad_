#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;
    int front, rear, capacity, size;

public:
    // Constructor to initialize queue
    Queue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor to free memory
    ~Queue()
    {
        delete[] arr;
    }

    // Enqueue operation (Insert element)
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = value;
        size++;
    }

    // Dequeue operation (Remove element)
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! No elements to dequeue." << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity; // Circular increment
        size--;
        return val;
    }

    // Peek operation (Get front element)
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Check if queue is full
    bool isFull()
    {
        return size == capacity;
    }

    // Display queue elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

// Main function to test queue
int main()
{
    Queue q(5); // Create queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    cout << "Dequeued element: " << q.dequeue() << endl;
    q.display();

    return 0;
}
