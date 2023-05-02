class Solution {
    
    public boolean dfs(int i,int j,char[][] board,int idx ,String word)
    {
        if(idx==word.length())
            return true;
        if(i<0 || i>=board.length || j<0 || j>=board[0].length || board[i][j]!=word.charAt(idx))
            return false;
        
        char c=board[i][j];
        board[i][j]='#';
        
        boolean ans=false;
        
        ans=ans | dfs(i-1,j,board,idx+1,word);
        ans=ans | dfs(i+1,j,board,idx+1,word);
        ans=ans | dfs(i,j-1,board,idx+1,word);
        ans=ans | dfs(i,j+1,board,idx+1,word);
        
        board[i][j]=c;
        return ans;
        
    }
    public boolean exist(char[][] board, String word) {
        
        int n=board.length;
        int m=board[0].length;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word.charAt(0))
                {
                    if(dfs(i,j,board,0,word))
                        return true;
                }
            }
        }
        
        return false;
    }
}