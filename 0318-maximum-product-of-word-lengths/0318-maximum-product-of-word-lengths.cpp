class Solution {
public:
    bool compare(string &s,string &t)
    {
        for(int i=0;i<26;i++)
        {
            if(s[i]=='1' && t[i]=='1')
                return false;
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        
        string t="";
        for(int i=0;i<26;i++)
        {
            t+="0";
        }
        vector<string> mp(words.size());
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            string temp=t;
            
            for(int j=0;j<s.length();j++)
            {
                temp[s[j]-'a']='1';
            }
            mp[i]=temp;
            
        }
        
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            string x=words[i];
            int l1=x.length();
            for(int j=i+1;j<words.size();j++)
            {
                string y=words[j];
                int l2=y.length();
                if(compare(mp[i],mp[j]))
                {
                    ans=max(ans,l1*l2);
                }
            }
        }
        
        return ans;
        
    }
};