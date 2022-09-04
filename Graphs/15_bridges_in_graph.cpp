#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, unordered_map<int, bool> &vis, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adjList)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    
    for (auto neighbour : adjList[node])
    {
        if (neighbour == parent)
            continue;
        if (!vis[neighbour])
        {
            dfs(neighbour, node, timer, vis, disc, low, result, adjList);
            low[node] = min(low[node], low[neighbour]);
            
            // check for the bridge edge
            if (low[neighbour] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                
                result.push_back(ans);
            }
        }
        else 
        {
            // back edge is present
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Creation of adjList
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    int timer = 0;
    vector<int> low(v);
    vector<int> disc(v);
    int parent = -1;
    
    for (int i = 0; i < v; i++)
    {
        low[i] = -1;
        disc[i] = -1;
    }
    unordered_map<int, bool> vis;
    
    // dfs
    vector<vector<int>> result;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, parent, timer, vis, disc, low, result, adjList);
    }
    return result;
}

int main()
{
    int nodes, edge;
    cout << "Enter the number of vertices : ";
    cin >> nodes;

    cout << "Enter the number of edges : ";
    cin >> edge;

    vector<vector<int>> edges(edge, vector<int>(2));

    cout << "Enter the pair of edges" << endl;

    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> ans = findBridges(edges, nodes, edge);

    cout << "Total number of bridges present : " << ans.size() << endl;

    cout << "The edges containing the bridges are "<<endl;

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}