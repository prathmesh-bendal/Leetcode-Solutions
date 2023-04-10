class Solution {
    
    public boolean check(int m,int[] nums,int p)
    {
        int count=0;
        
        int flag=0;
        
        for(int i=0;i<nums.length-1;i++)
        {
            if(flag==1)
            {
                flag=0;
                continue;
            }
            
            if(nums[i+1]-nums[i]<=m)
            {
                count++;
                flag=1;
            }
        }
        
        return count>=p;
    }
    public int minimizeMax(int[] nums, int p) {
        
        Arrays.sort(nums);
        
        int n=nums.length;
        int low=0,high=nums[n-1]-nums[0];
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            
            if(check(mid,nums,p))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
        
        
        
    }
}