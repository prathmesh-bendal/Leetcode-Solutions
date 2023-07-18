class DSU {

public:
    vector<int> par,rank;
    int components;
    
    DSU (int n)
    {
        par=vector<int>(n);
        rank=vector<int>(n,1);
        components=n;
        
        for(int i=0;i<n;i++)
            par[i]=i;
        
        
    }
    
    int getParent(int x)
    {
        if(x==par[x])
            return x;
        
        
        return par[x]=getParent(par[x]);
    }
    
    bool merge(int x,int y)
    {
        int a=getParent(x);
        int b=getParent(y);
        
        if(a==b)
            return false;
        
        
        if(rank[a]>rank[b])
        {
            par[b]=a;
        }
        else if(rank[b]>rank[a])
        {
            par[a]=b;
        }
        else
        {
            par[b]=a;
            rank[a]++;
        }
        components--;
        return true;
    }
    
    bool isConnected()
    {
        if(components==1)
            return true;
        
        return false;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        
        DSU* dsua=new DSU(n);
        DSU* dsub=new DSU(n);
        int required=0;
        for(int i=0;i<edges.size();i++)
        {
            int type=edges[i][0];
            int u=edges[i][1]-1;
            int v=edges[i][2]-1;
            
            
            if(type==3)
            {
                bool flag1=dsua->merge(u,v);
                bool flag2=dsub->merge(u,v);
                if(flag1 || flag2 )
                {
                    required++;
                }
            }
        }
        
        for(int i=0;i<edges.size();i++)
        {
            int type=edges[i][0];
            int u=edges[i][1]-1;
            int v=edges[i][2]-1;
            
            
            if(type==1)
            {
                if(dsua->merge(u,v) )
                {
                    required++;
                }
            }
            else if(type==2)
            {
                if(dsub->merge(u,v) )
                {
                    required++;
                }
                
            }
        }
        
        if(dsua->isConnected() && dsub->isConnected())
        {
            return edges.size()-required;
        }
        
        return -1;
            
        
        
        
    }
};