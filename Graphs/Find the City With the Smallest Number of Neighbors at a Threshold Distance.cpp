class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        
        for(auto i : edges)
        {
            distance[i[0]][i[1]]=i[2];
            distance[i[1]][i[0]]=i[2];
        }
        
        for(int i=0;i<n;i++) distance[i][i]=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(distance[j][i]==INT_MAX||distance[i][k]==INT_MAX)
                    {
                        continue;
                    }
                    else
                    {
                        distance[k][j]=min(distance[k][j],distance[j][i]+distance[i][k]);
                    }
                    
                }
            }
        }
        
        int cityNo=-1;
        int maxCount=n;
        
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(distance[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            
            if(count<=maxCount)
            {
                maxCount=count;
                cityNo=i;
            }
        }
        
        return cityNo;
        
    }
};
