#include<unordered_map>
#include<list>
#include<stack>


void topologicalsort(stack<int> &st,unordered_map<int,list<int>> adjlist,int v,unordered_map<int,bool> &visited,int node)
{
	visited[node]=true;

	for(auto nbr: adjlist[node])
	{
		if(!visited[nbr])
		{
			topologicalsort(st,adjlist,v,visited,nbr);
		}
		
	}

	st.push(node);

	return ;
}

void dfs(stack<int> &st,int node,unordered_map<int,bool> &visited,
			unordered_map<int,list<int>> &transpose)
{
	visited[node]=true;

	for(auto nbr:transpose[node])
	{
        if (!visited[nbr]) 
		{
            dfs(st, nbr, visited, transpose);
        }
    }

	return ;

}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adjlist;

	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];

		adjlist[u].push_back(v);
	}

	stack <int>st;
	unordered_map<int,bool> visited;

	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			topologicalsort(st,adjlist,v,visited,i);
		}
		
	}
	

	

	unordered_map<int,list<int>> transpose;

	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		for(auto nbr:adjlist[i])
		{
			transpose[nbr].push_back(i);
		}
	}


	int count=0;

	while(!st.empty())
	{
		int i=st.top();
		st.pop();
        if (!visited[i])
		{
            count++;
            dfs(st, i, visited, transpose);
        }
    }

        return count;
}
        
