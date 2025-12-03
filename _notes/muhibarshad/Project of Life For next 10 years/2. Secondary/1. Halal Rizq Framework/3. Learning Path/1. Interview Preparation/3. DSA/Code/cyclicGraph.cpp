#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList() : head(nullptr) {}

    void insert(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    bool search(int key)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }
};

class Graph
{
    int V;
    LinkedList *adj;

    bool DFS(int v, bool visited[], int parent)
    {
        visited[v] = true;

        Node *temp = adj[v].head;
        while (temp)
        {
            int u = temp->data;
            if (!visited[u])
            {
                if (DFS(u, visited, v))
                    return true;
            }
            else if (u != parent)
                return true; // Cycle detected
            temp = temp->next;
        }
        return false;
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj = new LinkedList[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].insert(w);
        adj[w].insert(v); // Undirected graph
    }

    bool hasCycle()
    {
        bool *visited = new bool[V]();
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && DFS(i, visited, -1))
                return true;
        }
        delete[] visited;
        return false;
    }

    ~Graph() { delete[] adj; }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
