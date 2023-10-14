class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans="";
        
        for(int j=0;j<strs[0].length();j++)
        {
            for(auto s:strs)
            {
                if(s.length()==j || s[j]!=strs[0][j])
                    return ans;
            }
            ans+=strs[0][j];
        }
        return ans;
            
        
    }
};