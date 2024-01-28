vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++)
    {
        int p=edges[i][0];
        int q=edges[i][1];

        adjlist[p].push_back(q);
    }

    vector<int> indegree(v);


    for(auto i: adjlist)
    {
        for(auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;

    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty())
    {
        int front=q.front();

        ans.push_back(front);
        q.pop();

        for(auto neighbour: adjlist[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
