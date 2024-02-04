#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) 
{
    unordered_map<int,list<pair<int,int>>> adjlist;

    for(int i=0;i<edges;i++)
    {
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        
        adjlist[u].push_back(make_pair(v,w));
        adjlist[v].push_back(make_pair(u,w));

    }

    vector<int> dist(vertices);

    for(int i=0;i<vertices;i++)
    {
        dist[i]=INT_MAX;
    }
    set<pair<int,int>> s;
    dist[source]=0;

    s.insert(make_pair(0,source));

    while(!s.empty())
    {
        auto top=*(s.begin());
        s.erase(s.begin());

        for(auto neighbour : adjlist[top.second])
        {
            
            if(top.first+neighbour.second<dist[neighbour.first])
            {
                auto record=s.find(make_pair(dist[neighbour.first],neighbour.first));
                if(record !=s.end())
                {
                    s.erase(record);
                }
                dist[neighbour.first]=top.first+neighbour.second;
                s.insert(make_pair(dist[neighbour.first],neighbour.first));
                
            }
        }
    }
    

    return dist;

    
}
