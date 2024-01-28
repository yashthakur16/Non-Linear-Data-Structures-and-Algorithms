int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges)
{
  unordered_map<int,list<int>> adjlist;

  for(int i=0;i<edges.size();i++)
  {
    int u=edges[i].first-1;
    int v=edges[i].second-1;

    adjlist[u].push_back(v);
  }

  vector<int> indegree(n);


    for(auto i: adjlist)
    {
        for(auto j : i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;

    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    int cnt=0;

    while(!q.empty())
    {
        int front=q.front();

        cnt++;
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


    if(cnt==n)
    {
      return false;
    }
    else
    {
      return true;
    }
