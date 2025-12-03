#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    // Constructor to initialize stack
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Destructor to free memory
    ~Stack()
    {
        delete[] arr;
    }

    // Push operation (Insert element)
    void push(int value)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    // Pop operation (Remove element)
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! No elements to pop." << endl;
            return -1;
        }
        return arr[top--];
    }

    // Peek operation (Get top element)
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check if stack is full
    bool isFull()
    {
        return top == capacity - 1;
    }

    // Display stack elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function to test stack
int main()
{
    Stack s(5); // Create stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Top element: " << s.peek() << endl;

    cout << "Popped element: " << s.pop() << endl;
    s.display();

    return 0;
}
