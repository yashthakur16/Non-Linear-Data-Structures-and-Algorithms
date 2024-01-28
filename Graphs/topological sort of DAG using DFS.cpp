#include <bits/stdc++.h> 

void dfs(unordered_map<int,list<int>> &adjlist,vector<bool> &visited,stack<int> &st,int node)
{
    visited[node]=true;

    for(auto neighbour : adjlist[node])
    {
        if(!visited[neighbour])
        {
            dfs(adjlist,visited,st,neighbour);
        }
    }

    st.push(node);
    return ;

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++)
    {
        int p=edges[i][0];
        int q=edges[i][1];

        adjlist[p].push_back(q);
    }

    vector<bool> visited(v);
    vector<int> ans;
    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(adjlist,visited,st,i);
        }
    }

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}
