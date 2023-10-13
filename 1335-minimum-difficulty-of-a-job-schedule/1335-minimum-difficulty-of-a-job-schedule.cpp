class Solution {
public:
    int dp[301][11];
    int solve(vector<int> &job,int idx,int n,int d)
    {
        if(dp[idx][d]!=-1)
            return dp[idx][d];
        if(d==1)
        {
            int mx=job[idx];
            for(int i=idx;i<n;i++)
                mx=max(mx,job[i]);
            
            return dp[idx][d]=mx;
        }
        
        int ans=INT_MAX;
        int mx=job[idx];
        
        for(int i=idx;i<=n-d;i++)
        {
            mx=max(mx,job[i]);
            ans=min(ans,mx+solve(job,i+1,n,d-1));
        }
        return dp[idx][d]=ans;
    }
    int minDifficulty(vector<int>& job, int d) {
        
        int n=job.size();
        if(n<d)
            return -1;
        
        memset(dp,-1,sizeof(dp));
        
        return solve(job,0,n,d);
        
    }
};