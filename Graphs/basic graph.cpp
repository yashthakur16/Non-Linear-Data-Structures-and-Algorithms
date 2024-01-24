#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;


class Graph
{
    public:

    unordered_map<char,list<char>> adj;

    void add_edge(char n,char v,bool direction)
    {
        adj[n].push_back(v);

        if(direction==0)
        {
            adj[v].push_back(n);
        }
        return;
    }

    void print()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
        return ;
    }


};

int main()
{
    Graph g;
    
    //add edges to the graph
    int m=0;
    cout<<"Number of nodes: ";
    cin>>m;

    for(int i=0;i<m;i++)
    {
        char n,v;
        cin>>n>>v;
        g.add_edge(n,v,1);
    }

    g.print();

    return 0;
}
