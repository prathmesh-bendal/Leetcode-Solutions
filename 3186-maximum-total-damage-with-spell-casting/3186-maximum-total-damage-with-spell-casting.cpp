class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        map<int,int> mp;
        
        for(auto i:power)
        {
            mp[i]++;
        }
        
        
        
        unordered_map<int,long long> incl,excl;
        
        long long ans=0;
        
        for(auto it:mp)
        {
            int n=it.first;
            int f=it.second;
            auto previt=mp.lower_bound(n-2);
            int prev=-1;
            if(previt!=mp.begin())
            {
                previt--;
                prev=(*previt).first;
            }
            
            long long nincl=1LL*n*f;
            if(prev!=-1)
                nincl+=max(incl[prev],excl[prev]);
            long long nexcl=max(incl[n-1],incl[n-2]);
            nexcl=max(nexcl,excl[n-1]);
            nexcl=max(nexcl,excl[n-2]);
            
            ans=max(ans,max(nincl,nexcl));
            incl[n]=nincl;
            excl[n]=nexcl;
        }
        return ans;
        
        
    }
};