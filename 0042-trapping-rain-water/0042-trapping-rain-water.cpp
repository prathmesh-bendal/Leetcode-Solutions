class Solution {
public:
    int trap(vector<int>& height) {
        
        int leftMax=0,rightMax=0;
        int ans=0;
        
        int i=0,j=height.size()-1;
        while(i<=j)
        {
            if(leftMax<rightMax)
            {
                leftMax=max(leftMax,height[i]);
                ans+=leftMax-height[i];
                i++;
            }
            else
            {
                rightMax=max(rightMax,height[j]);
                ans+=rightMax-height[j];
                j--;
            }
        }
        return ans;
        
    }
};