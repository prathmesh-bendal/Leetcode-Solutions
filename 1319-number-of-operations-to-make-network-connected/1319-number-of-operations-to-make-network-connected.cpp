class DSU{
  public:
    vector<int> par;
    vector<int> rank;
    
    DSU(int n)
    {
        par=vector<int>(n);
        rank=vector<int>(n,1);
        
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
    }
    
    int getParent(int x)
    {
        if(x==par[x])
            return x;
        
        return par[x]=getParent(par[x]);
    }
    
    void merge(int x,int y)
    {
        int a=getParent(x);
        int b=getParent(y);
        if(a==b)
            return;
        if(rank[a]>rank[b])
        {
            par[b]=a;
        }
        else if(rank[a]<rank[b])
        {
            par[a]=b;
        }
        else
        {
            par[b]=a;
            rank[a]++;
        }
    }
    
    bool areConnected(int x,int y)
    {
        int a=getParent(x);
        int b=getParent(y);
        if(a==b)
            return true;
        
        return false;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int components=n;
        int unused=0;
        
        
        DSU* dsu=new DSU(n);
        
        for(auto v:connections)
        {
            int x=v[0];
            int y=v[1];
            if(dsu->areConnected(x,y))
            {
                unused++;
            }
            else
            {
                dsu->merge(x,y);
                components--;
            }
            
        }
        
        if(components==1)
            return 0;
        
        if(components-1>unused)
            return -1;
        
        return components-1;
        
    }
};