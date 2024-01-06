class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int ans=0;
        
        int sum=0;
        for(int i=0;i<k;i++)
            sum+=arr[i];
        
        if((sum/k)>=threshold)
            ans++;
        
        int i=0,j=k;
        
        while(j<arr.size())
        {
            sum+=arr[j];
            sum-=arr[i];
            
            if((sum/k)>=threshold)
                ans++;
            
            j++;
            i++;
        }
        return ans;
        
    }
};