class Solution {
public:
    bool static cmp(vector<int> &a,vector<int> &b)
    {
        return (b[1]-b[0])<(a[1]-a[0]);
    }
    bool solve(int m,vector<vector<int>>& tasks)
    {
        int curr=m;
        for(auto v:tasks)
        {
            if(curr<v[1])
                return false;
            else if(curr<v[0])
            {
                return false;
            }
            else
            {
                curr-=v[0];
            }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(),tasks.end(),cmp);
        
        // for(int i=0;i<tasks.size();i++)
        // {
        //     cout<<tasks[i][0]<<" "<<tasks[i][1]<<endl;
        // }
        
        int l=0,r=0;
        
        for(auto v:tasks)
        {
            r+=v[0]+v[1];
        }
        int ans=r;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            
            if(solve(m,tasks))
            {
                ans=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        return ans;
        
    }
};