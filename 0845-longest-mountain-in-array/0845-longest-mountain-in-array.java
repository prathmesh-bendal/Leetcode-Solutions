class Solution {
    public int longestMountain(int[] arr) {
        int ans=0,start=0;
        int n=arr.length;
        
        while(start<n)
        {
            int end=start;
            if(end+1<n && arr[end]<arr[end+1])
            {
                while(end+1<n && arr[end]<arr[end+1])
                    end++;
                
                
                if(end+1<n && arr[end]>arr[end+1])
                {
                    while(end+1<n && arr[end]>arr[end+1])
                        end++;
                    
                    
                    ans=Math.max(ans,end-start+1);
                }
            }
            start=Math.max(end,start+1);
        }
        return ans;
        
        
    }
}