class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
        int left[n],right[n];
        
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,nums[i]);
            left[i]=mx;
        }
        
        int mn=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            mn=min(mn,nums[i]);
            right[i]=mn;
        }
        
        int l=-1;
        for(int i=0;i<n-1;i++)
        {
        
            if(left[i]>right[i])
            {
                l=i;
                break;
            }
        }
        if(l==-1)
            return 0;
        
        int r=-1;
        for(int i=n-1;i>0;i--)
        {
            if(right[i]<left[i])
            {
                r=i;
                break;
            }
        }
        return r-l+1;
    }
};