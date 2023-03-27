class Solution {
    public int maxSubArray(int[] nums) {
        
        int maxSumTillHere=0;
        int ans=Integer.MIN_VALUE;
        
        
        for(int i=0;i<nums.length;i++)
        {
            maxSumTillHere+=nums[i];
            
            ans=Math.max(ans,maxSumTillHere);
            maxSumTillHere=Math.max(0,maxSumTillHere);
        }
        
        return ans;
        
    }
}