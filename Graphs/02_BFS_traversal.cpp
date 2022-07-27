#include<bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        // prepare adjacency list for undirected graph
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        
        // store frontNode into ans
        ans.push_back(frontNode);
        
        // traverse all neighbours of frontNode
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    prepareAdjList(adjList, edges);
    
    // traverse all components of graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
            bfs(adjList, visited, ans, i);
    }
    return ans;
}

int main()
{
    int vertex;
    int edge;

    cout << "Enter the number of vertices : ";
    cin>> vertex;

    cout << "Enter the number of edges : ";
    cin>> edge;

    vector<pair<int, int>> edges(edge);

    cout << "Enter the "<< edge <<" pairs of the edges ---"<<endl;

    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i].first;
        cin >> edges[i].second;
    }

    vector<int> ans = BFS(vertex, edges);

    // print the answer
    for (auto i : ans)
        cout << i << " ";

    cout <<endl;

    return 0;
}