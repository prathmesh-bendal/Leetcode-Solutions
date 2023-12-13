class Solution {
public:
    int solve(vector<vector<int>> &grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=1;j<m-1;j++)
            {
                if(grid[i][j]==1)
                {
                    if(grid[i+1][j-1]==1 && grid[i+1][j]==1 && grid[i+1][j+1]==1)
                    {
                        dp[i][j]=1+min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]));
                        ans+=dp[i][j];
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
    int countPyramids(vector<vector<int>>& grid) {
        
        
        int upward=solve(grid);
        reverse(grid.begin(),grid.end());
        
        int downward=solve(grid);
        
        return upward+downward;
    }
};