class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        long long ans=0;
        int n=nums.size();
        int prev=nums[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>prev)
            {
                int curr=nums[i]/prev;
                if(nums[i]%prev!=0)
                {
                    curr++;
                    
                }
                ans+=1LL*curr-1;
                prev=nums[i]/curr;
            }
            else
            {
                prev=nums[i];
            }
                
        }
        return ans;
    }
};