class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        
        unordered_map<int,int> left,right,freq;
        int mx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(left.find(nums[i])==left.end())
                left[nums[i]]=i;
            
            right[nums[i]]=i;
            
            freq[nums[i]]++;
            mx=max(mx,freq[nums[i]]);
        }
        
        
        int ans=nums.size();
        for(auto i:freq)
        {
            if(i.second==mx)
            {
                ans=min(ans,right[i.first]-left[i.first]+1);
            }
        }
        return ans;
        
       
        
    }
};