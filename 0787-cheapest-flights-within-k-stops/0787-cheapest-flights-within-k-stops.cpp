class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        unordered_map<int,list<pair<int,int>>> adj;
        
        for(auto v:flights)
        {
            adj[v[0]].push_back({v[1],v[2]});
        }
        
        vector<int> dist(n,1e9);
        vector<int> stops(n,1e9);
        
        typedef pair<int,pair<int,int>> node;
        priority_queue<node,vector<node>,greater<node>> pq;
        
        dist[src]=0;
        stops[src]=-1;
        
        pq.push({0,{-1,src}});
        
        while(pq.size()>0)
        {
            auto curr=pq.top();
            pq.pop();
            
            int d=curr.first;
            int steps=curr.second.first;
            int u=curr.second.second;
            
            if(u==dst)
            {
                return d;
            }
            
            if(steps==k)
                continue;
            
            for(auto np:adj[u])
            {
                int nextDist=d+np.second;
                int nextSteps=steps+1;
                
                
                int v=np.first;
                
                if(dist[v]>nextDist || nextSteps<stops[v])
                {
                    dist[v]=nextDist;
                    stops[v]=nextSteps;
                    pq.push({nextDist,{nextSteps,v}});
                }
            }
        }
        
        
        
        return -1;
        
        
        
        
    }
};