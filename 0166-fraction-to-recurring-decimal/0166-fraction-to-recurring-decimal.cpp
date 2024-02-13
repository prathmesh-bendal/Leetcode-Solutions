class Solution {
public:
    string getSubstring(int l,int r,string s)
    {
        string res="";
        
        for(int i=l;i<=r;i++)
            res+=s[i];
        
        return res;
    }
    string fractionToDecimal(int numerator, int denominator) {
        
        int num=abs(numerator);
        int den=abs(denominator);
        
        string ans="";
        
        
        long long q=num/den;
        long long r=num%den;
        
        ans+=to_string(q);
        
        if(r!=0)
        {
            ans+='.';
            unordered_map<int,int> mp;
            
            while(r!=0)
            {
                if(mp.find(r)!=mp.end())
                {
                    string res=getSubstring(0,mp[r]-1,ans);
                    res+='(';
                    res+=getSubstring(mp[r],ans.length()-1,ans);
                    res+=')';
                    ans=res;
                    break;
                    
                }
                else
                {
                    mp[r]=ans.length();
                    r=r*10;
                    q=r/den;
                    ans+=to_string(q);
                    r=r%den;
                }
            }
        }
        
        if(numerator<0 && denominator>0 || numerator>0 && denominator<0)
            ans="-"+ans;
        
        return ans;
        
    }
};