class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        unordered_map<int,list<int>> adj;
        vector<int> indegree(n,0);
        for(auto v:relations)
        {
            adj[v[0]-1].push_back(v[1]-1);
            indegree[v[1]-1]++;
        }
        
        queue<int> q;
        
        vector<int> maxTime(n,INT_MIN);
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                maxTime[i]=time[i];
            }
        }
        
        
        while(q.size()>0)
        {
            int u=q.front();
            q.pop();
            for(auto v:adj[u])
            {
                maxTime[v]=max(maxTime[v],maxTime[u]+time[v]);
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        int ans=0;
        for(auto i:maxTime)
            ans=max(ans,i);
        return ans;
        
        
        
    }
};