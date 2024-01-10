#include <bits/stdc++.h> 
 class node
   {
       public:
       int data;
       int i;
       int j;

       node(int data,int i,int j)
       {
           this->data=data;
           this->i=i;
           this->j=j;
       }
   };

   class compare
   {
       public:
       bool operator()(node* a,node* b)
       {
           return a->data > b->data;
       }
   };

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
  

   priority_queue<node*,vector<node*>,compare> pq;

   for(int i=0;i<k;i++)
   {
       node* temp=new node(kArrays[i][0],i,0);
       pq.push(temp);
   }

   vector<int> ans;
   
   while(pq.size()>0)
   {
       node* temp=pq.top();
       
       ans.push_back(temp->data);
       pq.pop();

       int i=temp->i;
       int j=temp->j;

       if(j+1<kArrays[i].size())
       {
            temp=new node(kArrays[i][j+1],i,j+1);
            pq.push(temp);
       }
   }

   return ans;
}
