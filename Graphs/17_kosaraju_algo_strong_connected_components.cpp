#include<bits/stdc++.h>
using namespace std;

// depth - first search function
void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s, unordered_map<int, list<int>> &adjList)
{
    vis[node] = true;
    for (auto neighbour: adjList[node])
    {
        if (!vis[neighbour])
            dfs(neighbour, vis, s, adjList);
    }
    
    // topological Sort Logic
    s.push(node);
}

// depth - first search function for the transpose of the graph
void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adjList)
{
    vis[node] = true;
    for (auto neighbour: adjList[node])
    {
        if (!vis[neighbour])
        {
            revDfs(neighbour, vis, adjList); 
        }
    }
}

// function to find the SSC in the graph
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    // create a stack 
    stack<int> s;
    
    // create a visited map
    unordered_map<int, bool> vis;
    
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, s, adjList);
        }
    }
    
    // create a transpose of the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
        for (auto nbr: adjList[i])
            transpose[nbr].push_back(i);
    }
    
    // call dfs for the transpose graph
    int count = 0; // count variable for calculating SSC
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!vis[top])
        {
            count++;
            revDfs(top, vis, transpose);
        }
    }
    return count; // return the count of SSC
}

int main()
{
    int node, edge;
    cout << "Enter the number of the vertices : ";
    cin >> node;

    cout << "Enter the number of edges : ";
    cin >> edge;

    vector<vector<int>> edges(edge, vector<int> (2));
    cout << "Enter the pairs of the edges" << endl;
    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    int connectedSource = stronglyConnectedComponents(node, edges);

    cout << "Strongly Connected Components in the graph is : " << connectedSource << endl;
    
    return 0;
}