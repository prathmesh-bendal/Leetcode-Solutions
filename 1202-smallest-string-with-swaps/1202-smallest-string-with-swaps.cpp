class Solution {
public:
    
    void dfs(int u,vector<bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &index,string &order,string &s)
    {
        visited[u]=true;
        index.push_back(u);
        order+=s[u];
        
        
        for(auto v:adj[u])
        {
            if(visited[v]==false)
            {
                dfs(v,visited,adj,index,order,s);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        unordered_map<int,list<int>> adj;
        
        for(auto v:pairs)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        
        
        int n=s.length();
        vector<bool> visited(n,false);
        
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                vector<int> index;
                string order="";
                dfs(i,visited,adj,index,order,s);
                
                
                sort(index.begin(),index.end());
                sort(order.begin(),order.end());
                
                for(int j=0;j<index.size();j++)
                {
                    s[index[j]]=order[j];
                }
            }
        }
        
        return s;
        
    }
};