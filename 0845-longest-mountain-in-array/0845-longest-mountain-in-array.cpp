class Solution {
public:
    int longestMountain(vector<int>& a) {
        
        int ans=0;
        int start=0,end=0;
        int n=a.size();
        while(end<n)
        {
            end=start;
            if(end+1<n && a[end]<a[end+1])
            {
                while(end+1<n && a[end]<a[end+1])
                    end++;
                
                if(end+1<n && a[end]>a[end+1])
                {
                    while(end+1<n && a[end]>a[end+1])
                        end++;
                    
                    ans=max(ans,end-start+1);
                }
            }
            start=max(start+1,end);
        }
        return ans;
    }
};