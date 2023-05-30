class Solution {
    public boolean isMatch(String s, String p) {
        int n=p.length();
        int m=s.length();
        boolean dp[][]=new boolean[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
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
                    if(p.charAt(i-1)!='*')
                    {
                        dp[i][j]=false;
                    }
                    else
                    {
                        dp[i][j]=dp[i-2][j];
                    }
                }
                else
                {
                    if(p.charAt(i-1)=='*')
                    {
                        dp[i][j]=dp[i-2][j];
                        
                        if(p.charAt(i-2)=='.' || p.charAt(i-2)==s.charAt(j-1))
                        {
                            dp[i][j]=dp[i][j] | dp[i][j-1];
                        }
                    }
                    else if(p.charAt(i-1)=='.')
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else if(p.charAt(i-1)==s.charAt(j-1))
                    {
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
            }
        }
        return dp[n][m];
        
    }
}