class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        
        if(y>=x)
            return y-x;
        
        
        int end=x+11;
        
        queue<pair<int,int>> q;
        
        q.push({x,0});
        set<int> vis;
        vis.insert(x);
        while(q.size()>0)
        {
            auto p=q.front();
            q.pop();
            int u=p.first;
            int d=p.second;
            if(u==y)
                return d;
            if(u+1<=end && vis.find(u+1)==vis.end())
            {
                vis.insert(u+1);
                q.push({u+1,d+1});
            }
            if(u-1>=0 && u>y && vis.find(u-1)==vis.end())
            {
                vis.insert(u-1);
                q.push({u-1,d+1});
            }
            
            if(u%11==0 && vis.find(u/11)==vis.end())
            {
                vis.insert(u/11);
                q.push({u/11,d+1});
            }
            
            if(u%5==0 && vis.find(u/5)==vis.end())
            {
                vis.insert(u/5);
                q.push({u/5,d+1});
            }
            
            
        }
        
        return -1;
        
    }
};