#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
   unordered_map<int,list<pair<int,int>>> adj;

   for(int i=0;i<m;i++)
   {
       int u=g[i].first.first;
       int v=g[i].first.second;
       int w=g[i].second;

       adj[u].push_back(make_pair(v,w));
       adj[v].push_back(make_pair(u,w));
   }

   vector<int> key(n+1);
   vector<bool> mst(n+1);
   vector<int> parent(n+1);

   for(int i=1;i<=n;i++)
   {
       key[i]=INT_MAX;
       parent[i]=-1;
       mst[i]=false;
   }
   key[1]=0;


   for(int i=1;i<=n;i++)
   {
       int mini=INT_MAX;
       int u;

       for(int v=1;v<=n;v++)
       { 
           if(mst[v]==false && key[v]<mini)
           {
               mini=key[v];
               u=v;
           }
       }

       mst[u]=true;

       for(auto neighbour:adj[u])
       {
           if(mst[neighbour.first]==false&&neighbour.second<key[neighbour.first])
           {
               key[neighbour.first]=neighbour.second;
               parent[neighbour.first]=u;
           }
       }
   }

   vector<pair<pair<int, int>, int>> ans;

   for(int i=2;i<=n;i++)
   {
       ans.push_back({{parent[i], i}, key[i]});
   }

   return ans;


}
