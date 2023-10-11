#include<iostream>
using namespace std;

void heapify(int arr[],int i,int n)
{
    int index=i;
    int left=index*2;
    int right=index*2+1;

    if(left<n && arr[left]>arr[index])
    {
        index=left;
    }
    if(right<n && arr[right]>arr[index])
    {
        index=right;
    }

    if(index !=i)
    {
        swap(arr[i],arr[index]);
        heapify(arr,index,n);
    }
    else
    {
        return ;
    }
    
}

int main()
{
    int arr[6]={-1,65,83,34,5,43};
    int n=5;

    for(int i=n/2;i>0;i--)
    {
        heapify(arr,i,5);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
