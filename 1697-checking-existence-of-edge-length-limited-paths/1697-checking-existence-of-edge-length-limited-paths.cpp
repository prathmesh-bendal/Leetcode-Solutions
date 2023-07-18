class DSU{
public:
    
    vector<int> par,rank;
    
    DSU(int n)
    {
        par=vector<int>(n);
        rank=vector<int>(n,1);
        
        for(int i=0;i<n;i++)
            par[i]=i;
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
        else if(rank[b]>rank[a])
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
    bool static cmp(vector<int> &a,vector<int> &b)
    {
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
            
        }
        
        vector<bool> ans(queries.size(),false);
        
        sort(queries.begin(),queries.end(),cmp);
        
        sort(edgeList.begin(),edgeList.end(),cmp);
        
        DSU* dsu=new DSU(n);
        
        int i=0,j=0;
        cout<<"a"<<endl;
        while(i<queries.size())
        {
            while(j<edgeList.size() && edgeList[j][2]<queries[i][2])
            {
                dsu->merge(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            
            ans[queries[i][3]]=dsu->areConnected(queries[i][0],queries[i][1]);
            // ans[0]=true;
            i++;
            
        }
        return ans;
    }
};