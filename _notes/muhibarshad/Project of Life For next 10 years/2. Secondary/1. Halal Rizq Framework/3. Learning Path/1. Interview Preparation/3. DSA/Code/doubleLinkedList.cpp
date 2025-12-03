#include <iostream>
using namespace std;

class DoublyLinkedList
{
    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data) : data(data), next(NULL), prev(NULL) {}
    };
    Node *head;
    Node *tail;

    void Reverse(Node *cur)
    {
        if (cur == NULL)
            return;
        Node *temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        if (cur->prev == NULL)
            head = cur;
        else
            Reverse(cur->prev);
    }

public:
    DoublyLinkedList() { head = tail = NULL; }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }

    int count()
    {
        int c = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }

    int sum()
    {
        int sum = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    int max()
    {
        if (!head)
            return 0;
        int max = head->data;
        Node *temp = head;
        while (temp != NULL)
        {
            if (max < temp->data)
                max = temp->data;
            temp = temp->next;
        }
        return max;
    }

    int min()
    {
        if (!head)
            return 0;
        int min = head->data;
        Node *temp = head;
        while (temp != NULL)
        {
            if (min > temp->data)
                min = temp->data;
            temp = temp->next;
        }
        return min;
    }

    void InsertAtEnd(int n)
    {
        Node *newNode = new Node(n);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void InsertAtStart(int n)
    {
        Node *newNode = new Node(n);
        if (!head)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void Insert(int pos, int n)
    {
        if (pos < 1 || pos > count() + 1)
            return;
        Node *newNode = new Node(n);
        if (pos == 1)
            InsertAtStart(n);
        else if (pos == count() + 1)
            InsertAtEnd(n);
        else
        {
            Node *temp = head;
            for (int i = 1; i < pos - 1 && temp; i++)
                temp = temp->next;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    int Delete(int pos)
    {
        if (pos < 1 || pos > count())
            return -1;
        Node *temp = head;
        int x;
        if (pos == 1)
        {
            head = head->next;
            if (head)
                head->prev = NULL;
            x = temp->data;
            delete temp;
        }
        else
        {
            for (int i = 1; i < pos; i++)
                temp = temp->next;
            temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            else
                tail = temp->prev;
            x = temp->data;
            delete temp;
        }
        return x;
    }

    bool isSorted()
    {
        Node *temp = head;
        while (temp && temp->next)
        {
            if (temp->data > temp->next->data)
                return false;
            temp = temp->next;
        }
        return true;
    }

    void Reverse()
    {
        Reverse(head);
    }

    ~DoublyLinkedList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            head = temp;
            temp = temp->next;
            delete head;
        }
    }
};
