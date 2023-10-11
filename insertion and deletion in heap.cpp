#include<iostream>
using namespace std;

class heap
{
    public:

    int *arr=new int;
    int size=0;

    heap()
    {
        arr[0]=-1;
        size=0;
    }

    void insert(int val)
    {
        size=size+1;
        int index=size;
        arr[index]=val;

        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else
            {
                return ;
            }
        }
    }

    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    void deletefromHeap()
    {
        if(size==0)
        {
            cout<<"Nothing to delete ";
            return ;
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size)
        {
            int leftindex=i*2;
            int rightindex=i*2+1;
            if(leftindex<size && arr[leftindex]> arr[i])
            {
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && arr[rightindex]> arr[i])
            {
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else
            {
                return ;
            }
        }
        
    }

};

int main()
{
    heap h;
    h.insert(5);
    h.insert(34);
    h.insert(65);
    h.insert(43);
    h.insert(81);
    h.insert(3);

    h.print();
    cout<<endl;

    h.deletefromHeap();
    h.print();

    return 0;
    
}
