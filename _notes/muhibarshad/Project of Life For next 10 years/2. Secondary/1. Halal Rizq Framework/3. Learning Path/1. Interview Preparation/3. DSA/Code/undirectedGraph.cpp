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

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

class Graph
{
    int V;
    LinkedList *adj; // Array of linked lists

    void DFSHelp(int v, bool visited[])
    {
        visited[v] = true;
        cout << v << " ";

        Node *temp = adj[v].head;
        while (temp)
        {
            if (!visited[temp->data])
                DFSHelp(temp->data, visited);
            temp = temp->next;
        }
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj = new LinkedList[V]; // Array of linked lists
    }

    void addEdge(int v, int w)
    {
        adj[v].insert(w);
        adj[w].insert(v); // Undirected graph
    }

    void DFS(int v)
    {
        bool *visited = new bool[V]();
        cout << "DFS Traversal (Starting from " << v << "): ";
        DFSHelp(v, visited);
        cout << endl;
        delete[] visited;
    }

    void DFSDisconnected()
    {
        bool *visited = new bool[V]();

        cout << "DFS Traversal of Disconnected Graph: \n";
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                cout << "Starting new DFS from vertex " << i << ": ";
                DFSHelp(i, visited);
                cout << endl;
            }
        }
        delete[] visited;
    }

    void displayGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << ": ";
            adj[i].display();
            cout << endl;
        }
    }

    ~Graph()
    {
        delete[] adj;
    }
};

int main()
{
    Graph g(7); // 7 vertices (0 to 6)

    // First component
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Second component
    g.addEdge(5, 6);

    g.displayGraph();
    g.DFSDisconnected(); // Calls DFS for all disconnected components

    return 0;
}
