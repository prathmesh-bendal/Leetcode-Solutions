class Solution {
    public String longestPalindrome(String s) {
        int n=s.length();
        boolean dp[][]=new boolean[n][n];
        
        int ans=1;
        int start=0;
        int end=0;
        for(int len=1;len<=n;len++)
        {
            for(int i=0;i<n;i++)
            {
                int j=i+len-1;
                if(j>=n)
                    break;
                
                if(i==j)
                {
                    dp[i][j]=true;
                    if(len>ans)
                    {
                        ans=len;
                        start=i;
                        end=j;
                    }
                }
                else if(j-i==1)
                {
                    if(s.charAt(i)==s.charAt(j))
                    {
                        dp[i][j]=true;
                        if(len>ans)
                        {
                            ans=len;
                            start=i;
                            end=j;
                        }
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                else
                {
                    if(s.charAt(i)==s.charAt(j) && dp[i+1][j-1]==true)
                    {
                        dp[i][j]=true;
                        if(len>ans)
                        {
                            ans=len;
                            start=i;
                            end=j;
                        }
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
            }
        }
        return s.substring(start,end+1);
    }
}