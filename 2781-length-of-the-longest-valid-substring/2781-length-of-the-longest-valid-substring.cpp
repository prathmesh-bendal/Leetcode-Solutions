class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        
        unordered_map<string,int> mp;
        for(auto s:forbidden)
        {
            mp[s]++;
        }
        
        int ans=0;
        int end=word.length()-1;
        
        for(int i=word.length()-1;i>=0;i--)
        {
            string curr="";
            for(int j=i;j<=min(end,i+9);j++)
            {
                curr+=word[j];
                if(mp[curr]>0)
                {
                    end=j-1;
                    break;
                }
            }
            ans=max(ans,end-i+1);
        }
        return ans;
        
    }
};