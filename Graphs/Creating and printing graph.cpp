vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int> ans[n];

    for(int i=0;i<m;i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];

        ans[a].push_back(b);
        ans[b].push_back(a);

    }

    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++)
    {
        adj[i].push_back(i);

        for(int j=0;j<ans[i].size();j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }

    return adj;
}
