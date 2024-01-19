#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string,int> m;

    m["yash"]=8;
    m["rohan"]=9;
    m["aditya"]=7;
    m["kaushik"]=6;

    cout<<"size = "<<m.size()<<endl;
    cout<<m.at("rohan")<<endl;

    unordered_map<string,int>::iterator it=m.begin();

    while(it != m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    m.erase("aditya");
    cout<<"size = "<<m.size()<<endl;

    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;


}
