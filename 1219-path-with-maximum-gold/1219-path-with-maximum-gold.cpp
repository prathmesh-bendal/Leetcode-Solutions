class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int solve(int x,int y,vector<vector<int>>& grid)
    {
        int val=grid[x][y];
        int mx=0;
        grid[x][y]=0;
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]!=0)
            {
                mx=max(mx,solve(nx,ny,grid));
            }
        }
        grid[x][y]=val;
        return mx+val;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int ans=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    ans=max(ans,solve(i,j,grid));
                }
            }
        }
        return ans;
        
    }
};