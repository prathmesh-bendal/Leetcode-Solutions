class Solution {
public:
    int dp[501][501];
    int m=1e9+7;
    int solve(int idx,int remain,int n)
    {
        if(remain==0)
        {
            if(idx==0)
                return 1;
            
            return 0;
        }
        
        if(dp[idx][remain]!=-1)
            return dp[idx][remain];
        
        int ans=solve(idx,remain-1,n)%m;
        
        if(idx>0)
        {
            ans+=solve(idx-1,remain-1,n)%m;
            ans=ans%m;
        }
        
        if(idx<n-1)
        {
            ans+=solve(idx+1,remain-1,n)%m;
            ans=ans%m;
        }
        
        return dp[idx][remain]=ans;
    }
    
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        memset(dp,-1,sizeof(dp));
        
        return solve(0,steps,arrLen);
        
    }
};