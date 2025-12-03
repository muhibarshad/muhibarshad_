#include <iostream>
using namespace std;

class DoublyCircularLinkedList
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

public:
    DoublyCircularLinkedList() { head = tail = NULL; }

    void InsertAtStart(int n)
    {
        Node *newNode = new Node(n);
        if (!head)
        {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }

    void InsertAtEnd(int n)
    {
        Node *newNode = new Node(n);
        if (!head)
        {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void Delete(int n)
    {
        if (!head)
            return;
        Node *temp = head;
        do
        {
            if (temp->data == n)
            {
                if (temp == head && temp == tail)
                {
                    delete temp;
                    head = tail = NULL;
                    return;
                }
                if (temp == head)
                {
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                }
                else if (temp == tail)
                {
                    tail = tail->prev;
                    tail->next = head;
                    head->prev = tail;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void Traverse()
    {
        if (!head)
            return;
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void Reverse()
    {
        if (!head || head->next == head)
            return;
        Node *cur = head, *temp = NULL;
        do
        {
            temp = cur->next;
            cur->next = cur->prev;
            cur->prev = temp;
            cur = temp;
        } while (cur != head);
        tail = head;
        head = head->prev;
    }
};

int main()
{
    DoublyCircularLinkedList dcll;
    dcll.InsertAtEnd(1);
    dcll.InsertAtEnd(2);
    dcll.InsertAtEnd(3);
    dcll.Traverse();
    dcll.Reverse();
    dcll.Traverse();
    dcll.Delete(2);
    dcll.Traverse();
    return 0;
}
