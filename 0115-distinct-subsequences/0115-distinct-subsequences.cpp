class Solution {
public:
    int dp[1001][1001];
    int solve(int i,string &s,int j,string &t)
    {
        if(j==t.length())
            return 1;
        
        if(i==s.length())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        
        for(int idx=i;idx<s.length();idx++)
        {
            if(s[idx]==t[j])
            {
                ans+=solve(idx+1,s,j+1,t);
            }
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s,0,t);
        
    }
};