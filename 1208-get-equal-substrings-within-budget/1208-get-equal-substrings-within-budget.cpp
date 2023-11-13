class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int ans=0;
        
        int i=0,j=0;
        int sum=0;
        
        while(j<s.length())
        {
            sum+=abs(t[j]-s[j]);
            
            while(sum>maxCost)
            {
                sum-=abs(t[i]-s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};