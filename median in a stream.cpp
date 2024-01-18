#include<queue>

int signum(int a,int b)
{
    if(a==b)
    {
        return 0;
    }
    else if (a<b)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int call_median(int element,priority_queue<int> &maxheap,priority_queue<int,vector<int>,greater<int>> &minheap,int median)
{
    int s=signum(maxheap.size(),minheap.size());

    if(s==0)
    {
        if(element<median)
        {
            maxheap.push(element);
            return maxheap.top();
        }
        else
        {
            minheap.push(element);
            return minheap.top();
        }
    }
    if(s==-1)
    {
        if(element<median)
        {
            maxheap.push(element);
            return (maxheap.top()+minheap.top())/2;
        }
        else
        {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(element);
            return (maxheap.top()+minheap.top())/2;

        }
    }
    if(s==1)
    {
        if(element<median)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
            maxheap.push(element);
            return (maxheap.top()+minheap.top())/2;
        }
        else
        {
            minheap.push(element);
            return (maxheap.top()+minheap.top())/2;

        }
    }

    return 0;
}


vector<int> findMedian(vector<int> &arr, int n)
{
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
	vector<int> ans;

    int median=0;
    for(int i=0;i<n;i++)
    {
        int element=arr[i];
        median=call_median(element,maxheap,minheap,median);
        ans.push_back(median);
    }

    return ans;
}
