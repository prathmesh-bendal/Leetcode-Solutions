class Solution {
    public void moveZeroes(int[] nums) {
        
        int n=nums.length;
        int idx=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                nums[idx]=nums[i];
                idx++;
            }
            else
                count++;
        }
        
        while(idx<n)
        {
            nums[idx]=0;
            idx++;
        }
        
        
    }
}