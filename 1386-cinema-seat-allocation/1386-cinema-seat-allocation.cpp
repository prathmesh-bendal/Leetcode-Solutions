class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        
        int ans=2*n;
        
        unordered_map<int,set<int>> mp;
        
        for(auto v:seats)
        {
            mp[v[0]].insert(v[1]);
        }
        
        for(auto it:mp)
        {
            bool flag=false;
            if(it.second.find(2)!=it.second.end() || it.second.find(3)!=it.second.end() || it.second.find(4)!=it.second.end() || it.second.find(5)!=it.second.end())
            {
                ans--;
            }
            else
            {
                flag=true;
            }
            if(it.second.find(8)!=it.second.end() || it.second.find(9)!=it.second.end() || it.second.find(6)!=it.second.end() || it.second.find(7)!=it.second.end())
            {
                ans--;
            }
            else
            {
                flag=true;
            }
            if(it.second.find(4)==it.second.end() && it.second.find(5)==it.second.end() && it.second.find(6)==it.second.end() && it.second.find(7)==it.second.end() && flag==false)
            {
                ans++;
            }
        }
        return ans;
        
        
    }
};