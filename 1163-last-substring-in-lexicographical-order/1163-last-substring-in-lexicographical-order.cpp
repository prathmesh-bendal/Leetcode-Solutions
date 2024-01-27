class Solution {
public:
    string lastSubstring(string s) {
        
        int index=s.length()-1;
        
        for(int j=s.length()-2;j>=0;j--)
        {
            int l=j,r=index;
            
            while(l<index && r<s.length())
            {
                if(s[l]==s[r])
                {
                    l++;
                    r++;
                }
                else
                    break;
            }
            if(l==index || r==s.length() || s[l]>s[r])
                index=j;
        }
        
        return s.substr(index);
        
    }
};