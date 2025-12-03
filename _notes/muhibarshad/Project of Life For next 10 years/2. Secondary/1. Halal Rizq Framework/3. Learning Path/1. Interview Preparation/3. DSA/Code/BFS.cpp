#include <iostream>
using namespace std;

// Node class for linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

// Linked list class for adjacency list and queue
class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    // Insert at the end (used for adjacency list and queue)
    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Remove from front (used for queue)
    int removeFront()
    {
        if (!head)
            return -1;
        Node *temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        return value;
    }

    // Check if list is empty
    bool isEmpty() { return head == nullptr; }
};

// Graph class using adjacency list
class Graph
{
    int V;
    LinkedList *adj; // Adjacency list array

public:
    Graph(int V)
    {
        this->V = V;
        adj = new LinkedList[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].insert(w);
        adj[w].insert(v); // For undirected graph
    }

    void BFS(int s)
    {
        bool *visited = new bool[V]();
        LinkedList queue; // Manually implemented queue

        visited[s] = true;
        queue.insert(s);

        while (!queue.isEmpty())
        {
            int current = queue.removeFront();
            cout << current << " ";

            Node *temp = adj[current].head;
            while (temp)
            {
                if (!visited[temp->data])
                {
                    visited[temp->data] = true;
                    queue.insert(temp->data);
                }
                temp = temp->next;
            }
        }
        delete[] visited;
    }

    void BFS_Disconnected()
    {
        bool *visited = new bool[V]();
        LinkedList queue;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.insert(i);

                while (!queue.isEmpty())
                {
                    int current = queue.removeFront();
                    cout << current << " ";

                    Node *temp = adj[current].head;
                    while (temp)
                    {
                        if (!visited[temp->data])
                        {
                            visited[temp->data] = true;
                            queue.insert(temp->data);
                        }
                        temp = temp->next;
                    }
                }
            }
        }
        delete[] visited;
    }

    void BFS_VertexORDER()
    {
        int *visited = new int[V]();
        int order = 1;
        LinkedList queue;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = order++;
                queue.insert(i);

                while (!queue.isEmpty())
                {
                    int current = queue.removeFront();
                    cout << current << " ";
                    Node *temp = adj[current].head;
                    while (temp)
                    {
                        if (!visited[temp->data])
                        {
                            visited[temp->data] = order++;
                            queue.insert(temp->data);
                        }
                        temp = temp->next;
                    }
                }
            }
        }
        delete[] visited;
    }

    ~Graph() { delete[] adj; }
};

int main()
{
    Graph g(6); // Creating a graph with 6 vertices (disconnected)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 4); // Disconnected component
    g.addEdge(4, 5);

    cout << "BFS for Connected Component (Starting from 0): ";
    g.BFS(0);
    cout << endl;

    cout << "BFS for Disconnected Graph: ";
    g.BFS_Disconnected();
    cout << endl;

    cout << "BFS with Vertex Order: ";
    g.BFS_VertexORDER();
    cout << endl;

    return 0;
}
