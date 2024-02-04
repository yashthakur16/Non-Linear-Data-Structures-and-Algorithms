#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) 
{
    unordered_map<int,list<pair<int,int>>> adj;

    for(int i=0;i<edges;i++)
    {
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }   

    vector<int> dist(vertices);

    for(int i=0;i<vertices;i++)
    {
        dist[i]=INT_MAX;
    }

    dist[source]=0;

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0,source));

    while(!pq.empty())
    {
        pair<int,int> top=pq.top();
        pq.pop();

        for(auto neighbour : adj[top.second])
        {
            if(top.first+neighbour.second<dist[neighbour.first])
            {
                dist[neighbour.first]=top.first+neighbour.second;
                pq.push(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }

    return dist;

}

