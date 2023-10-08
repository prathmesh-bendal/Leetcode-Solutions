class Solution {
public:
    int longestValidParentheses(string s) {
        
        int open=0,close=0,ans=0;
        
        for(auto c:s)
        {
            if(c=='(')
                open++;
            else
                close++;
            
            if(open==close)
                ans=max(ans,2*open);
            
            if(close>open)
                open=0,close=0;
        }
        open=0,close=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')
                open++;
            else
                close++;
            
            if(open==close)
                ans=max(ans,2*open);
            
            if(open>close)
                open=0,close=0;
        }
        return ans;
    }
};