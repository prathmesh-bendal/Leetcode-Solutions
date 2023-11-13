class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({grid[0][0],{0,0}});
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        while(pq.size()>0)
        {
            auto p=pq.top();
            pq.pop();
            
            int val=p.first;
            int x=p.second.first;
            int y=p.second.second;
            vis[x][y]=true;
            if(x==n-1 && y==m-1)
            {
                return val;
            }
            for(int d=0;d<4;d++)
            {
                int nx=x+dx[d];
                int ny=y+dy[d];
                
                if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==false)
                {
                    if(dist[nx][ny]>max(val,grid[nx][ny]))
                    {
                        dist[nx][ny]=max(val,grid[nx][ny]);
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
            
            
        }
        return 1;
       
        
    }
};