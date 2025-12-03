#include <iostream>
using namespace std;

class CircularQueue
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int val) : data(val), next(NULL) {}
    };

    Node *front, *rear;

public:
    // Constructor
    CircularQueue() { front = rear = NULL; }

    // Enqueue operation (Insert at rear)
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (!front)
        {
            front = rear = newNode;
            rear->next = front; // Circular link
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Maintain circular property
        }
    }

    // Dequeue operation (Remove from front)
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! No elements to dequeue." << endl;
            return -1;
        }

        int dequeuedValue = front->data;
        if (front == rear) // Only one element
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            rear->next = front; // Maintain circular link
            delete temp;
        }
        return dequeuedValue;
    }

    // Peek operation (Get front element)
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return front == NULL;
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
        Node *temp = front;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }

    // Destructor to free memory
    ~CircularQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

// Main function to test Circular Queue
int main()
{
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();

    cout << "Front element: " << cq.peek() << endl;

    cout << "Dequeued element: " << cq.dequeue() << endl;
    cq.display();

    return 0;
}
