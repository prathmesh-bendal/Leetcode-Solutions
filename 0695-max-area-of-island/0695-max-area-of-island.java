class Solution {
    
    public void dfs(int i,int j,int[][] grid,int[] count)
    {
        if(i<0 || i>=grid.length || j<0 || j>=grid[0].length || grid[i][j]==0)
            return;
        
        
        grid[i][j]=0;
        count[0]++;
        
        dfs(i-1,j,grid,count);
        dfs(i+1,j,grid,count);
        dfs(i,j-1,grid,count);
        dfs(i,j+1,grid,count);
        
    }
    public int maxAreaOfIsland(int[][] grid) {
        
        int ans=0;
        
        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[0].length;j++)
            {
                if(grid[i][j]==1)
                {
                    int []count=new int[1];
                    dfs(i,j,grid,count);
                    ans=Math.max(ans,count[0]);
                }
            }
        }
        return ans;
    }
}