class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        
        map<int,int> freq;
        priority_queue<pair<int,pair<int,int>>> pq;
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                freq[mat[i][j]]++;
                pq.push({mat[i][j],{i,j}});
            }
        }
        vector<pair<int,int>> v;
        for(auto it:freq)
        {
            v.push_back({it.first,it.second});
        }
        reverse(v.begin(),v.end());
        
        
        unordered_map<int,int> mpx,mpy;
        int ans=0;
        int idx=0;
        while(pq.size()>0)
        {
            vector<vector<int>> temp;
            while(v[idx].second--)
            {
                int u=pq.top().first;
                int x=pq.top().second.first;
                int y=pq.top().second.second;
                pq.pop();
                int curr=max(mpx[x],mpy[y])+1;
                
                ans=max(ans,curr);
                temp.push_back({curr,x,y});
                    
            }
            for(auto t:temp)
            {
                mpx[t[1]]=max(mpx[t[1]],t[0]);
                mpy[t[2]]=max(mpy[t[2]],t[0]);
            }
            idx++;
        }
        return ans;
        
        
    }
};