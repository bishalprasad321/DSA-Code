#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // creation of adjacency list
    unordered_map<int, list<pair<int, int> > > adjList;
    
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }
    
    // creation of required data structure
    vector<bool> mst(n+1);
    vector<int> key(n+1);
    vector<int> parent(n+1);
    
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    
    // assign the value for start/source
    key[1] = 0;
    parent[1] = -1;
    
    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        
        // find u -> node with minimum path weight
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false and key[v] < mini)
            {
                u = v; 
                mini = key[v];
            }
        }
        
        // mark the min node with true
        mst[u] = true;
        
        // check its adjacent nodes
        for (auto it : adjList[u])
        {
            int v = it.first;
            int w = it.second;
            
            if (mst[v] == false and w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> result;
    
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    
    return result;
}

int main()
{
    int nodes;
    int edge;
    vector<pair<pair<int, int>, int>> edges(edge);
    cout << "Enter the number of nodes : ";
    cin >> nodes;

    cout << "Enter the number of edges : ";
    cin >> edge;

    cout << "Enter the pairs of edges with weights alongside them"<<endl;

    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
    }

    cout << "The result using prim's Algo" << endl;

    vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(nodes, edge, edges);

    for (auto i : ans)
    {
        cout << i.first.first << " " << i.first.second << " " << i.second <<endl;
    }
    return 0;
}