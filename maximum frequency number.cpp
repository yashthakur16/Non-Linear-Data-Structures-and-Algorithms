#include<unordered_map>
#include<limits.h>

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> m;
    int maxfreq=0;

    for(int i=0;i<arr.size();i++)
    {
        m[arr[i]]++;
        maxfreq=max(m[arr[i]],maxfreq);
    }

    for(int i=0;i<n;i++)
    {
        if(maxfreq==m[arr[i]])
        {
            return arr[i];
        }
    }

    return -1;


}
