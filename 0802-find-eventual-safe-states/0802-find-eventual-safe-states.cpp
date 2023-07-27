class Solution {
public:
    bool dfs(int u,vector<bool>&vis,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &safe,vector<int> &ans)
    {
        bool flag=true;
        vis[u]=true;
        for(auto v:adj[u])
        {
            if(vis[v]==false)
            {
                flag=flag & dfs(v,vis,adj,safe,ans);
            }
            else
            {
                flag=flag & safe[v];
            }
        }
        
        safe[u]=flag;
        if(flag)
        {
            ans.push_back(u);
        }
        return flag;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        unordered_map<int,bool> safe;
        unordered_map<int,list<int>> adj;
        
        for(int i=0;i<graph.size();i++)
        {
            if(graph[i].size()==0)
            {
                safe[i]=true;
            }
            else
            {
                for(auto j:graph[i])
                {
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<bool> vis(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                dfs(i,vis,adj,safe,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};