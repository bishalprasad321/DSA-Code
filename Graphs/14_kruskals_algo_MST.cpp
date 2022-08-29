#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeParent(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i; // each node is the parent of itself
        rank[i] = 0; // rank of each node is zero as its the parent of itself
    }
}

int findParent(vector<int> &parent, int node)
{
    // base case : when the node has the parent as itself, then there is no more parent of the node
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    
    if (rank[u] < rank[v])
        parent[u] = v;
    
    else if (rank[v] < rank[u])
        parent[v] = u;
    
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(), edges.end(), cmp); // sort the edges vector by weight
    vector<int> parent(n);
    vector<int> rank(n);
    
    makeParent(parent, rank, n);
    
    int minWeight = 0;
    
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        
        if (u != v)
        {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}

int main()
{
    int nodes, edge;

    cout << "Enter the number of nodes : ";
    cin >> nodes;

    cout << "Enter the number of edges : ";
    cin >> edge;

    cout << "Enter the pairs of edges with the weight alongside them"<<endl;
    vector<vector<int>> edges(edge, vector<int> (3));

    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "The minimum spanning tree using Kruskal's Algorithm is : " << minimumSpanningTree(edges, nodes) << endl;
    
    return 0;
}