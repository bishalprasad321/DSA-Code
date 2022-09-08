#include<bits/stdc++.h>
using namespace std;

/*
    input : 0 3
            3 4
            0 4
            0 1
            1 2
*/

void dfs(int node, int parent, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &vis, vector<int> &disc, vector<int> &low, int &timer, vector<int> &ap)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;

    int child = 0;

    for (auto neighbour : adjList[node])
    {
        if (neighbour == parent)
            continue;

        if (!vis[neighbour])
        {
            dfs(neighbour, node, adjList, vis, disc, low, timer, ap);
            low[node] = min(low[node], low[neighbour]);

            // check ap condition
            if (low[neighbour] >= disc[node] and parent != -1)
            {
                ap[node] = 1;
            }

            child++;
        }

        else
        {
            low[node] = min(low[node], disc[neighbour]);
        }
    }

    if (parent == -1 and child > 1)
    {
        ap[node] = true;
    }
}

vector<int> articulationPoints (int v, int e, vector<pair<int, int>> &edges)
{
    // creation of adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    unordered_map<int, bool> vis;
    vector<int> ap(v, 0);

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, adjList, vis, disc, low, timer, ap);
        }
    }
    return ap;
}

int main()
{
    int nodes, edge;
    cout << "Enter the total number of nodes : ";
    cin >> nodes;

    cout << "Enter the number of edges : ";
    cin >> edge;

    vector<pair<int, int>> edges(edge);

    cout << "Enter the pairs of edges" << endl;
    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> result = articulationPoints(nodes, edge, edges);
    
    for (int i = 0; i < nodes; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}