#include<bits/stdc++.h>
using namespace std;

/*
    Kahn's Algorithm can be used to detect any cycle in a directed graph

    step 1 : find indegree of all nodes in the graph
    step 2 : push all the nodes with indegree = 0 into a queue
    step 3 : do the BFS traversal 
*/

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) 
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        
        adjList[u].push_back(v);
    }
    
    vector<int> indegree(n);
    
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
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    
    int count = 0;
    // do bfs
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        
        // increment the count 
        count++;
        
        // neighbour indegree update
        for (auto neighbour : adjList[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    if (count != n)
        return true;
    else
        return false;
}

int main()
{
    int nodes;
    cout << "Enter the number of nodes : ";
    cin >> nodes;

    int edge;
    cout << "Enter the number of edges : ";
    cin >> edge;

    vector<pair<int, int>> edges(edge);

    cout << "Enter the pairs of nodes"<<endl;

    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    cout << "Is there any cycle present in the given graph : ";

    if (detectCycleInDirectedGraph(nodes, edges))
        cout << "Yes"<<endl;
    
    else
        cout << "No" <<endl;
        
    return 0;
}