class Solution {
public:
    bool check(vector<bool> &seen,string s)
    {
        for(auto c:s)
        {
            if(seen[c-'a'])
                return false;
        }
        
        return true;
    }
    void solve(int idx,vector<string>&a,vector<bool> seen,int &ans,int curr)
    {
        if(idx==a.size())
        {
            ans=max(ans,curr);
            return;
        }
        
        solve(idx+1,a,seen,ans,curr);
        
        if(check(seen,a[idx]))
        {
            for(auto c:a[idx])
                seen[c-'a']=true;
            solve(idx+1,a,seen,ans,curr+a[idx].length());
        }
    }
    bool isValid(string s)
    {
        unordered_map<char,int>mp;
        for(auto c:s)
        {
            mp[c]++;
            if(mp[c]>1)
                return false;
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        
        int ans=0;
        vector<bool> seen(26,false);
        vector<string> a;
        for(auto s:arr)
        {
            if(isValid(s))
                a.push_back(s);
        }
        solve(0,a,seen,ans,0);
        return ans;
    }
};