class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,list<pair<int,int>>> adj;
        
        for(auto road:roads)
        {
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        
        vector<long long> dist(n,LLONG_MAX);
        vector<int> count(n,0);
        
        dist[0]=0;
        count[0]=1;
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        
        pq.push({0,0});
        int m=1e9+7;
        while(pq.size()>0)
        {
            long long t=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            
            for(auto neg:adj[u])
            {
                long long d=t+neg.second;
                int v=neg.first;
                if(dist[v]>d)
                {
                    dist[v]=d;
                    count[v]=count[u]%m;
                    pq.push({d,v});
                }
                else if(dist[v]==d)
                {
                    count[v]+=count[u];
                    count[v]=count[v]%m;
                }
                
            }
        }
        return count[n-1];
        
        
        
        
        
        
    }
};