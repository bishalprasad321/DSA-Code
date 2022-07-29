#include<bits/stdc++.h>
using namespace std;

bool isCycleBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);
    
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        
        for (auto neighbour : adjList[front])
        {
            if (visited[neighbour] and neighbour != parent[front])
                return true;
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create an adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    // visited data structure
    unordered_map<int, bool> visited;
    // handle all the components of the graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCycleBFS(i, visited, adjList);
            if (ans)
                return "Yes";
        }
    }
    return "No";
}

int main()
{
    int vertex;
    int edge;

    cout << "Enter the number of vertices : ";
    cin>> vertex;

    cout << "Enter the number of edges : ";
    cin>> edge;

    vector<vector<int>> edges (edge, vector<int>(2));

    cout << "Enter the "<< edge <<" pairs of the edges ---"<<endl;

    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i][0];
        cin >> edges[i][1];
    }

    string ans = cycleDetection(edges, vertex, edge);
    
    cout << "Do the graph has cycle? : "<< ans << endl;

    return 0;
}