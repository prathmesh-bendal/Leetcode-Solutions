class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        int n=plant.size();
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({grow[i],plant[i]});
        }
        
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        int day=0;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int bloom=day+v[i].second+v[i].first;
            ans=max(ans,bloom);
            day=day+v[i].second;
        }
        return ans;
        
    }
};