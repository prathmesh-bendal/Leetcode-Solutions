class Solution {
    public int islandPerimeter(int[][] grid) {
        
        
        int ans=0;
        
        int n=grid.length;
        int m=grid[0].length;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=4;
                    for(int d=0;d<4;d++)
                    {
                        int x=i+dx[d];
                        int y=j+dy[d];
                        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1)
                            ans--;
                    }
                }
            }
        }
        
        return ans;
        
        
    }
}