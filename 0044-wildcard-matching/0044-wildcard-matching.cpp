class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n=p.length();
        int m=s.length();
        
        bool dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            bool flag=false;
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=true;
                }
                else if(i==0)
                {
                    dp[i][j]=false;
                }
                else if(j==0)
                {
                    if(p[i-1]!='*')
                    {
                        dp[i][j]=false;
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    flag=flag | dp[i-1][j];
                }
                else
                {
                    if(p[i-1]=='*')
                    {
                        dp[i][j]=dp[i-1][j];
                        dp[i][j]=dp[i][j] | flag;
                    }
                    else if(p[i-1]=='?')
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                        if(p[i-1]==s[j-1])
                        {
                            dp[i][j]=dp[i-1][j-1];
                        }
                        else
                        {
                            dp[i][j]=false;
                        }
                    }
                    flag = flag | dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
        
    }
};