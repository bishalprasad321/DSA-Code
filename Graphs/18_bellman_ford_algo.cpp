#include<bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    for (int i = 1; i <= n; i++)
    {
        // traversing edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            
            if (dist[u] != 1e9 and (dist[u] + weight) < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    
    // check for the negative cycle
    bool flag = false;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        
        if (dist[u] != 1e9 and (dist[u] + weight) < dist[v])
            flag = !flag;
    }
    
    if (flag == 0)
        return dist[dest];
    
    else
        return -1;
}

int main()
{
    int nodes, edge, dest;
    cout << "Enter the total number of nodes : ";
    cin >> nodes;

    cout << "Enter the total number of edges : ";
    cin >> edge;

    vector<vector<int>> edges(edge, vector<int>(3));

    cout << "Enter the pairs of the edges along with their weights"<<endl;

    for (int i = 0; i < edge; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "Enter the node whose distance you want to find : ";
    cin >> dest;

    int ans = bellmonFord(nodes, edge, edges[0][0], dest, edges);

    if (ans != -1)
        cout << "The given node's shortest distance is : "<<ans<<endl;

    else
        cout << "The given Graph contains a negative cycle, so shortest path cannot be detected!!"<<endl;
    return 0;
}