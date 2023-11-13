class Solution {
public:
    
    int maxProduct(vector<string>& words) {
        
        string t="";
        for(int i=0;i<26;i++)
        {
            t+="0";
        }
        vector<int> mp(words.size());
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            string temp=t;
            
            for(int j=0;j<s.length();j++)
            {
                temp[s[j]-'a']='1';
            }
            int num=0;
            for(int j=0;j<26;j++)
            {
                num=num*2+(temp[j]-'0');
            }
            mp[i]=num;
            
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
                if((mp[i]^mp[j])==(mp[i]+mp[j]))
                {
                    ans=max(ans,l1*l2);
                }
            }
        }
        
        return ans;
        
    }
};