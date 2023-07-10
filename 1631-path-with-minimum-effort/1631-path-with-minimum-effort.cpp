class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(pq.size()>0)
        {
            auto p=pq.top();
            pq.pop();
            int d=p.first;
            int x=p.second.first;
            int y=p.second.second;
            
            if(x==n-1 && y==m-1)
                return d;
            
            
            for(int i=0;i<4;i++)
            {
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                
                if(nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    int newEffort=max(d,abs(heights[x][y]-heights[nx][ny]));
                    if(newEffort<dist[nx][ny])
                    {
                        dist[nx][ny]=newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }
            
            
        }
        return -1;
        
    }
};