#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // creation of adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    // creation of distance array with maximum distace possible
    vector<int> dist(vertices);

    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[source] = 0;

    // creation of set with (Node distance, node) configuration
    set<pair<int, int>> st;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // fetch the top node
        auto top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;

        // erase the top node now
        st.erase(st.begin());

        // traverse the neighbours of topnode
        for (auto neighbour : adjList[topNode])
        {
            if (neighbour.second + nodeDistance < dist[neighbour.first])
            {
                // find any previous record of the topNode
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // if record found then erase it
                if (record != st.end())
                {
                    st.erase(record);
                }

                // update the distance 
                dist[neighbour.first] = nodeDistance + neighbour.second;

                // insert the new record in the set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main()
{
    int vertices, edges, source;

    cout << "Enter the number of vertices : ";
    cin >> vertices;

    cout << "Enter the number of edges : ";
    cin >> edges;

    vector<vector<int>> vec(edges, vector<int>(3));

    cout << "Enter the edges with their respective weights -> (start, end, weight)"<<endl;

    for (int i = 0; i < edges; i++)
    {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }

    cout << "Enter the source node : ";
    cin >> source;

    vector<int> dijkstraSol = dijkstra(vec, vertices, edges, source);

    cout << "Nodes with the shortest path are : ";
    for (int i : dijkstraSol)
        cout << i << " ";
    
    cout << endl;

    return 0;
}