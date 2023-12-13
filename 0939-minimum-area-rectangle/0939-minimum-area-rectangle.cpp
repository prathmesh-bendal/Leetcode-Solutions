class Solution {
public:
    bool static cmp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    bool isPresent(int &u,vector<int> &v)
    {
        int l=0,r=v.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(v[m]==u)
                return true;
            else if(v[m]>u)
                r=m-1;
            else
                l=m+1;
        }
        return false;
        
    }
    int minAreaRect(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),cmp);
        
        unordered_map<int,vector<int>> gx,gy;
        
        for(int i=0;i<points.size();i++)
        {
            gx[points[i][0]].push_back(points[i][1]);
            gy[points[i][1]].push_back(points[i][0]);
        }
        int ans=INT_MAX;
        
        for(auto i:gy)
        {
            
            vector<int> v=i.second;
            
            for(int j=0;j<v.size()-1;j++)
            {
                for(int k=j+1;k<v.size();k++)
                {
                    int w=abs(v[k]-v[j]);
                    vector<int> temp;
                    
                    for(auto u:gx[v[j]])
                    {
                        if(isPresent(u,gx[v[k]]))
                        {
                            temp.push_back(u);
                        }
                    }
                    
                    int h=INT_MAX;
                    for(int p=1;p<temp.size();p++)
                    {
                        h=min(h,temp[p]-temp[p-1]);
                    }
                    if(h!=INT_MAX)
                    {
                        ans=min(ans,w*h);
                    }
                }
            }
        }
        if(ans==INT_MAX)
            return 0;
        
        return ans;
        
        
        
    }
};