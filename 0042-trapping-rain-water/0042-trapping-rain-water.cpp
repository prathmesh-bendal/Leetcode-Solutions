class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans=0;
        
        int l=0,r=height.size()-1;
        int leftMax=height[0];
        int rightMax=height[height.size()-1];
        
        while(l<r)
        {
            if(leftMax<rightMax)
            {
                ans+=max(leftMax-height[l+1],0);
                l++;
                leftMax=max(leftMax,height[l]);
            }
            else
            {
                ans+=max(rightMax-height[r-1],0);
                r--;
                rightMax=max(rightMax,height[r]);
            }
        }
        return ans;
        
    }
};