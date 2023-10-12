class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        
        int n=arr.size();
        int right[n+1];
        right[n]=INT_MAX;
        int mn=INT_MAX;
        
        for(int i=n-1;i>=0;i--)
        {
            mn=min(mn,arr[i]);
            right[i]=mn;
        }
        
        int mx=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,arr[i]);
            if(mx<=right[i+1])
                count++;
        }
        return count;
        
    }
};