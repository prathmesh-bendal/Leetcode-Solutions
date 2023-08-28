class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    mat[i][j]=-1;
                }
            }
        }
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int level=1;
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                auto p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                
                for(int d=0;d<4;d++)
                {
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    
                    if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]!=-1)
                    {
                        ans[nx][ny]=level;
                        q.push({nx,ny});
                        mat[nx][ny]=-1;
                    }
                }
            }
            level++;
            
        }
        return ans;
        
    }
    
};