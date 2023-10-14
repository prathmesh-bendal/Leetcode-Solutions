class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        
        map<int,int> mp;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int x=__gcd(k,nums[i]);
            int want=k/x;
            for(auto it:mp)
            {
                if(it.first%want==0)
                    ans+=1LL*it.second;
            }
            mp[x]++;
        }
        return ans;
        
    }
};