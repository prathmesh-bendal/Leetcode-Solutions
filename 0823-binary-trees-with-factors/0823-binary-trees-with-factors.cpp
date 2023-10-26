class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int> dp(n,1);
        
        int m=1e9+7;
        for(int i=1;i<n;i++)
        {
            int l=0,r=i-1;
            while(l<=r)
            {
                long long prod=1LL*arr[l]*arr[r];
                long long val=0;
                if(prod==1LL*arr[i])
                {
                    if(l==r)
                    {
                        val=1LL*dp[l]*dp[r];
                    }
                    else
                    {
                
                        val=1LL*dp[l]*dp[r]*2;
                    }
                    val=val%m;
                    dp[i]+=val;
                    dp[i]=dp[i]%m;
                    l++;
                    r--;
                }
                else if(prod<arr[i])
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=dp[i];
            ans=ans%m;
        }
        return ans;
        
    }
};