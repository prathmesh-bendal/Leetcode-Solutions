class Solution {
public:
    bool compare(string &s,int idx1,int idx2,int l)
    {
        int i=idx1,j=idx2;
        while(i<idx1+l && i<s.length() && j<idx2+l && j<s.length())
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j++;
        }
        return true;
    }
    string check(string &s,int l)
    {
        long long m=1e9+7;
        unordered_map<long long,list<int>> mp;
        
        long long hash=0;
        long long p=1;
        for(int i=0;i<l;i++)
        {
            hash=1LL*hash*26+(s[i]-'a');
            hash=hash%m;
            p=p*26;
            p=p%m;
        }
        mp[hash].push_back(0);
        int i=0,j=l;
        
        while(j<s.length())
        {
            long long newhash=1LL*hash*26;
            newhash=newhash%m;
            newhash+=(s[j]-'a');
            newhash=newhash%m;
            newhash-=((s[i]-'a')*p)%m;
            
            if(newhash<0)
                newhash+=m;
            
            // if(mp.find(newhash)!=mp.end())
            // {
            //     int idx=mp[newhash];
            //     return s.substr(idx,l);
            // }
            for(auto idx:mp[newhash])
            {
                if(compare(s,i+1,idx,l))
                {
                    return s.substr(idx,l);
                }
            }
            mp[newhash].push_back(i+1);
            j++;
            i++;
            hash=newhash;
        }
        return "";
        
    }
    string longestDupSubstring(string s) {
        
        int l=1,r=s.length();
        
        string ans="";
        while(l<=r)
        {
            int m=(l+r)/2;
            string val=check(s,m);
            if(val!="")
            {
                ans=val;
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return ans;
        
    }
};