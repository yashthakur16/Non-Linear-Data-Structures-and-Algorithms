class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        unordered_map<int,bool> mpp;
        
        for(auto i : nums)
        {
            mpp[i]=true;
        }
        
        int maxi=-1;
        
        for(auto i : nums)
        {
            int num=(-1)*i;
            if(mpp[num]==true&&abs(num)>maxi)
            {
                maxi=abs(num);
            }
        }
        
        return maxi;
    }
};
