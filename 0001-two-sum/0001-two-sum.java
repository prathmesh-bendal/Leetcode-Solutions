class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        int [] ans=new int[2];
        HashMap<Integer,Integer> mp=new HashMap<>();
        mp.put(nums[0],0);
        
        for(int i=1;i<nums.length;i++)
        {
            if(mp.containsKey(target-nums[i]))
            {
                ans[0]=mp.get(target-nums[i]);
                ans[1]=i;
                return ans;
            }
            mp.put(nums[i],i);
        }
        return ans;
        
    }
}