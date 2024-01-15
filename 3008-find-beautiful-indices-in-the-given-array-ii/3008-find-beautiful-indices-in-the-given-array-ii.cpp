class Solution {
public:
    void LPS(string &s,vector<int> &lps)
    {
        lps[0]=0;
        
        int len=0;
        int i=1;
        
        while(i<s.length())
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    set<int> kmp(string &pat,string &txt)
    {
        vector<int> lps(txt.length(),0);
        
        LPS(txt,lps);
        
        int i=0,j=0;
        set<int> ans;
        while(i<pat.length())
        {
            if(pat[i]==txt[j])
            {
                i++;
                j++;
            }
            if(j==txt.length())
            {
                ans.insert(i-txt.length());
                j=lps[j-1];
            }
            else if(i<pat.length() && pat[i]!=txt[j])
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    i++;
                }
            }
            
        }
        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        
        
        set<int> s1=kmp(s,a);
        set<int> s2=kmp(s,b);
        
        vector<int> ans;
        
        for(auto i:s1)
        {
            bool flag=false;
            auto it=s2.upper_bound(i);
            if(it!=s2.end())
            {
                if((*it-i)<=k)
                {
                    ans.push_back(i);
                    flag=true;
                }
            }
            
            if(flag==false)
            {
                if(it!=s2.begin())
                {
                    it--;
                    
                    if((i-*it)<=k)
                    {
                        ans.push_back(i);
                    }
                }
            }
        }
        return ans;
        
        
    }
};