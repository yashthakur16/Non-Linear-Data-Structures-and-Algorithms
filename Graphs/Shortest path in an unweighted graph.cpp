#include<queue>
#include<list>
#include<unordered_map>


void bfsShortest(unordered_map<int,list<int>> &adjlist,vector<bool> &visited,unordered_map<int,int> &parent,int node)
{
	visited[node]=true;
	parent[node]=-1;

	queue<int> q;
	q.push(node);

	while(!q.empty())
	{
		int front=q.front();
		q.pop();
		for(auto neighbour:adjlist[front])
		{
			if(!visited[neighbour])
			{
				q.push(neighbour);
				visited[neighbour]=true;
				parent[neighbour]=front;
			}
		}
	}

	return ;

}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t)
{

	unordered_map<int,list<int>> adjlist;

	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i].first;
		int v=edges[i].second;

		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}	

	vector<bool> visited(n);
	unordered_map<int,int> parent;

	bfsShortest(adjlist,visited,parent,s);

	vector<int> ans;



	while(t!=-1)
	{
		ans.push_back(t);
		t=parent[t];

		if(t==-1)
		{
			break;
		}

	}

	reverse(ans.begin(),ans.end());

	return ans;


	
}
