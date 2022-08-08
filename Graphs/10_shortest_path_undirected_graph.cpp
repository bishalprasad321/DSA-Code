#include<bits/stdc++.h>
using namespace std;

/*
    n -> number of nodes
    m -> total path
    s -> starting node
    t -> terminating or ending node
*/

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t)
{
	// create adjacency list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
        
	// do bfs 
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        
        for (auto i : adjList[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    
    // prepare the the shortest path
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);
    
    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main()
{
    int nodes, paths;
    int source, terminate;
    
    cout << "Enter the number of total nodes : ";
    cin >> nodes;

    cout << "Enter the number of total paths : ";
    cin >> paths;

    cout << "Enter the starting/source node : ";
    cin >> source;

    cout << "Enter the ending node : ";
    cin >> terminate;

    cout << "Enter the pairs of edges"<<endl;

    vector<pair<int, int>> edges(paths);

    for (int i = 0; i < paths; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> ans = shortestPath(edges, nodes, paths, source, terminate);

    cout << "The shortest path is : ";
    for (int i : ans)
        cout << i << " ";

    return 0;
}