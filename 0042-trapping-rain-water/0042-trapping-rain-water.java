class Solution {
    public int trap(int[] height) {
        
        
        int ans=0;
        
        int leftMax=0,rightMax=0;
        
        int i=0,j=height.length-1;
        
        while(i<=j)
        {
            if(leftMax<rightMax)
            {
                leftMax=Math.max(leftMax,height[i]);
                ans+=leftMax-height[i];
                i++;
            }
            else
            {
                rightMax=Math.max(rightMax,height[j]);
                ans+=rightMax-height[j];
                j--;
            }
        }
        return ans;
        
    }
}