class Solution {
public:
    int solve(vector<int> & nums,int l, int r)
    {
        int prod=1;
        for(int i=l;i<=r;i++)
        {
            prod=prod*(nums[i]/abs(nums[i]));
        }
        if(prod==1)
            return r-l+1;
        
        int ans=0;
        for(int i=l;i<=r;i++)
        {
            if(nums[i]<0)
            {
                ans=max(ans,r-(i+1)+1);
            }
                
        }
        
        for(int i=r;i>=l;i--)
        {
            if(nums[i]<0)
            {
                ans=max(ans,i-1-l+1);
            }
        }
        return ans;
    }
    int getMaxLen(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;
        int l=0,r=0;
        while(l<n)
        {
            while(l<n && nums[l]==0)
                l++;
            
            r=l+1;
            while(r<n && nums[r]!=0)
                r++;
            
            ans=max(ans,solve(nums,l,r-1));
            l=r+1;
            
        }
        
        return ans;
    }
};