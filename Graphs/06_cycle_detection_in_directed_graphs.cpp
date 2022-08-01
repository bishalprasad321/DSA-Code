#include<bits/stdc++.h>
using namespace std;

bool DFScycle(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &DFSvisited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    DFSvisited[node] = true;
    
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = DFScycle(neighbour, visited, DFSvisited, adjList);
            if (cycleDetected)
                return true;
        }
        else if (DFSvisited[neighbour])
        {
            // visited true
            return true;
        }
    }
    
    DFSvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) 
{
    // creation of adjacent list
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool cycleDetected = DFScycle(i, visited, DFSvisited, adjList);
            if (cycleDetected)
                return true;
        }
    }
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

    cout << "Now enter the pair of edges"<<endl;

    vector<pair<int, int>> edges;
    for (int i = 0; i < edge; i++)
    {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        edges.push_back(temp);
    }

    if (detectCycleInDirectedGraph(nodes, edges))
        cout << "Cycle detected!!" << endl;

    else
        cout << "No Cycle detected!!" << endl;

    return 0;
}