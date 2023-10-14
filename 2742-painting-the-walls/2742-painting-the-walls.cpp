class Solution {
public:
    int dp[502][502]; 
    int solve(int idx,int remain,vector<int> &cost,vector<int> &time)
    {
        if(remain<=0)
            return 0;
        
        if(idx==cost.size())
            return 1e9;
        
        if(dp[idx][remain]!=-1)
            return dp[idx][remain];
        
        
        int paint=cost[idx]+solve(idx+1,remain-1-time[idx],cost,time);
        int skip=solve(idx+1,remain,cost,time);
        
        return dp[idx][remain]=min(paint,skip);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int n=cost.size();
        memset(dp,-1,sizeof(dp));
        
        return solve(0,n,cost,time);
        
        
    }
};