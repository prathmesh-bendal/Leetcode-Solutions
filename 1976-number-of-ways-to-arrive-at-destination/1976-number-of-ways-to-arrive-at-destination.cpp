class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<pair<long long,long long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> pq;
        // queue<pair<long long,long long>> pq;
        vector<long long > dist(n,LLONG_MAX);
        vector<long long> no_of_ways(n,0);
        pq.push({0,0});
        dist[0]=0;
        no_of_ways[0]=1;
        while(!pq.empty()){
            long long node=pq.top().second;
            long long d=pq.top().first;
            pq.pop();

            for(auto it : adj[node]){
                if((long long)d+it.second<dist[it.first]){
                    pq.push({d+it.second,it.first});
                    dist[it.first]=d+it.second;
                    no_of_ways[it.first]=no_of_ways[node]%mod;
                }
                else if((long long)d+it.second==dist[it.first]){
                    no_of_ways[it.first]=(no_of_ways[it.first]+no_of_ways[node])%mod;
                }
            }
        }

        return no_of_ways[n-1]%mod;
        
    }
};