class Solution {
public:
    bool haveCommonStop(vector<int> &a,vector<int> &b)
    {
        int i=0,j=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]==b[j])
                return true;
            
            if(a[i]<b[j])
                i++;
            else
                j++;
        }
        
        return false;
    }
    bool isStopPresent(vector<int> &a,int x)
    {
        int l=0,r=a.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(a[m]==x)
                return true;
            
            if(a[m]<x)
            {
                l=m+1;
            }
            else
                r=m-1;
        }
        return false;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source==target)
            return 0;
        
        unordered_map<int,list<int>> adj;
        
        for(int i=0;i<routes.size();i++)
        {
            sort(routes[i].begin(),routes[i].end());
        }
        for(int i=0;i<routes.size();i++)
        {
            for(int j=i+1;j<routes.size();j++)
            {
                if(haveCommonStop(routes[i],routes[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        queue<int> q;
        vector<bool> vis(routes.size(),false);
        int busCount=1;
        
        for(int i=0;i<routes.size();i++)
        {
            if(isStopPresent(routes[i],source))
            {
                q.push(i);
                vis[i]=true;
            }
        }
        
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                int u=q.front();
                q.pop();
                
                if(isStopPresent(routes[u],target))
                {
                    return busCount;
                }
                
                for(auto v:adj[u])
                {
                    if(vis[v]==false)
                    {
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
            busCount++;
        }
        return -1;
        
        
        
    }
};