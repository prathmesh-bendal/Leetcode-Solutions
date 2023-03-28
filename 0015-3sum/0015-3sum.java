class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        Arrays.sort(nums);
        
        List<List<Integer>> ans=new ArrayList<>();
        
        for(int i=0;i<nums.length-2;i++)
        {
            if(i==0 || (i>0 && nums[i]!=nums[i-1]))
            {
                int j=i+1;
                int k=nums.length-1;
                while(j<k)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        List<Integer> temp=new ArrayList<>();
                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(nums[k]);
                        ans.add(temp);
                        
                        while(j<k && nums[j]==nums[j+1])
                            j++;
                        
                        while(k>j && nums[k]==nums[k-1])
                            k--;
                        
                        j++;
                        k--;
                            
                    }
                    else if(nums[i]+nums[j]+nums[k]<0)
                    {
                        j++;
                    }
                    else
                    {
                        k--;
                    }

                    
                }
                
            }
        }
        
        return ans;
        
    }
}