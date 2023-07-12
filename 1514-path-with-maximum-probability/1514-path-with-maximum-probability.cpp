class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {

        unordered_map<int,list<pair<int,double>>> adj;
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],prob[i]});
            adj[edges[i][1]].push_back({edges[i][0],prob[i]});
        }
        
        
        priority_queue<pair<double,int>> pq;
        
        pq.push({1.0000,start});
        vector<double> dist(n,0);
        dist[start]=1.00000;
        while(pq.size()>0)
        {
            auto p=pq.top();
            pq.pop();
            double  d=p.first;
            int u=p.second;
            
            for(auto nbr:adj[u])
            {
                int v=nbr.first;
                double w=nbr.second;
                double nextProb=1.00000*d*w;
                
                if(nextProb>dist[v])
                {
                    dist[v]=nextProb;
                    pq.push({nextProb,v});
                }
            }
        }
        return dist[end];

        
    }
};