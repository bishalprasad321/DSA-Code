#include<bits/stdc++.h>
using namespace std;

/*
    Kahn's Algorithm can be used to detect any cycle in a directed graph

    step 1 : find indegree of all nodes in the graph
    step 2 : push all the nodes with indegree = 0 into a queue
    step 3 : do the BFS traversal 
*/

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    // creation of adjacency list 
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
    }
    
    vector<int> indegree(v, 0);
    
    // find indegree of all nodes
    for (auto i : adjList)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    
    // push the elements to queue with 0 indegree
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    
    // do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        
        // neighbour indegree update
        for (auto neighbour : adjList[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
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