class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left=0,right=nums.size()-1;
        
        
        while(left<=right)
        {
            int m=(left+right)/2;
            
            if(nums[m]==target)
                return m;
            
            if(nums[m]>=nums[left])
            {
                if(target>=nums[left] && target<=nums[m])
                {
                    right=m-1;
                }
                else
                {
                    left=m+1;
                }
            }
            else
            {
                if(target>=nums[m] && target<=nums[right])
                {
                    left=m+1;
                }
                else
                {
                    right=m-1;
                }
            }
        }
        return -1;
    }
};