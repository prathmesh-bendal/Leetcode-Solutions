class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<vector<int>> p;
        
        for(auto v:buildings)
        {
            p.push_back({v[0],-v[2]});
            p.push_back({v[1],v[2]});
        }
        
        
        sort(p.begin(),p.end());
        multiset<int> active ;
        active.insert(0);
        
        
        vector<vector<int>> ans;
        int currHeight=0;
        for(auto v:p)
        {
            int x=v[0];
            int h=v[1];
            
            if(h<0)
            {
                active.insert(-h);
            }
            else
            {
                auto it=active.find(h);
                active.erase(it);
            }
            auto it1=active.end();
            it1--;
            
            if(currHeight!=*it1)
            {
                ans.push_back({x,*it1});
                currHeight=*it1;
            }
        }
        return ans;
    }
};