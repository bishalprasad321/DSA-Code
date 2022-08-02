#include<bits/stdc++.h>
using namespace std;

void topoSortUtil(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adjList) 
{
    visited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
            topoSortUtil(neighbour, visited, s, adjList);
    }

    // push the element into the stack at the return of the function
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> edges, int v, int e)
{
    unordered_map<int, list<int>> adjList;
    // creation of adjacency list
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topoSortUtil(i, visited, s, adjList);
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    int nodes;
    cout << "Enter the number of nodes : ";
    cin >> nodes;

    int edge;
    cout << "Enter the number of edges : ";
    cin >> edge;

    vector<vector<int>> edges(edge, vector<int>(2));

    cout << "Enter the pairs of nodes"<<endl;

    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << "The topological sort of the above given graph is : ";
    vector<int> ans = topologicalSort(edges, nodes, edge);

    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}