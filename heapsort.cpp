#include<iostream>
using namespace std;

void heapify(int arr[],int i,int n)
{
    int index=i;
    int left=2*index;
    int right=2*index+1;

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

void heapsort(int arr[],int n)
{
   while(n>1)
   {
    swap(arr[1],arr[n]);
    n--;
    heapify(arr,1,n);
   }

   return ;
    


}

int main()
{
    int arr[6]={-1,81,65,34,5,43};
    int n=5;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    heapsort(arr,n);

    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;

}
