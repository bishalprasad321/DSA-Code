#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        unordered_map<int, list<int>> adj;


        void addEdge(int start, int end, bool direction = false)
        {
            // by default direction = false (i.e. undirected graph)
            // direction = true or 1 (i.e. graph is directed)

            // create an edge from start to end
            adj[start].push_back(end);

            // check for undirected graph
            if (!direction)
            {
                adj[end].push_back(start);
            }
        }

        void printAdjList()
        {
            for (auto i : adj)
            {
                cout << i.first << "-> ";
                for (auto j : i.second)
                {
                    cout << j << ", ";
                }
                cout << endl;
            }
        }   
};

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin>> n;

    int m;
    cout << "Enter the number of edges : ";
    cin>> m;

    Graph graph;

    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        // creating an undirected graph

        graph.addEdge(start, end, true);
    }

    // printing graph
    graph.printAdjList();

    return 0;
}