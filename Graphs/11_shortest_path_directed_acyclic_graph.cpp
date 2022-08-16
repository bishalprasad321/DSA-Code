#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

        void addEdge(int u, int v, int weight)
        {
            pair<int, int> p = make_pair(v, weight);
            adjList[u].push_back(p);
        }

        void printAdjList()
        {
            for (auto i : adjList)
            {
                cout << i.first << "-> ";
                for (auto j : i.second)
                {
                    cout << "[" << j.first <<", " << j.second <<"]";
                }
                cout << endl;
            }
        }

        void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topological)
        {
            visited[node] = true;
            for (auto neighbour : adjList[node])
            {
                if (!visited[neighbour.first])
                {
                    dfs(neighbour.first, visited, topological);
                }
            }
            topological.push(node);
        }

        void getShortestPath(int src, vector<int> &dist, stack<int> &topo)
        {
            dist[src] = 0;

            while (!topo.empty())
            {
                int top = topo.top();
                topo.pop();

                if (dist[top] != INT_MAX)
                {
                    for (auto i : adjList[top])
                    {
                        if ((dist[top] + i.second) < i.first)
                        {
                            dist[i.first] = dist[top] + i.second;
                        }
                    }
                }
            }
        }
};

int main()
{
    Graph g;

    unordered_map<int, bool> visited;
    stack<int> topo;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdjList();

    int nodes = 6;

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, topo);
        }
    }

    int src = 1;
    vector<int> dist(nodes);

    for (int i = 0; i < nodes; i++)
    {
        dist[i] = INT_MAX;
    }

    g.getShortestPath(src, dist, topo);

    cout << "Shortest path is : ";

    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}