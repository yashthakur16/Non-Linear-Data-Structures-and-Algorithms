#include<queue>
#include<unordered_map>
#include<list>

bool bfs(vector<vector<int>>& edges,unordered_map<int,list<int>> 
            &adjlist,unordered_map<int,bool> &visited,unordered_map<int,int> &parent,int node)
        {

            parent[node]=-1;


            queue<int> q;
            q.push(node);
            visited[node]=true;

            while(!q.empty())
            {
                int temp=q.front();
                q.pop();
                
                for(auto i: adjlist[temp])
                {
                    if(visited[i]==true&&i!=parent[temp])
                    {
                        return false;
                    }
                    else if(!visited[i])
                    {
                        q.push(i);
                        visited[i]=1;
                        parent[i]=temp;
                    }
                       
                }
                
            }

            return true;

        }



string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(!bfs(edges,adjlist,visited,parent,i))
            {
                return "Yes";
            }
        }
    }

    return "No";
}
