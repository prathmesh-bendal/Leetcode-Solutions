class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        
        int max_till_here=0;
        int ans=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            max_till_here+=nums[i];
            ans=max(ans,max_till_here);
            
            max_till_here=max(0,max_till_here);
            
        }
        return ans;
    }
};