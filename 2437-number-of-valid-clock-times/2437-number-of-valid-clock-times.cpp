class Solution {
public:
    bool isValid(string time)
    {
        int h=(time[0]-'0')*10+(time[1]-'0');
        int m=(time[3]-'0')*10+(time[1]-'0');
        
        if(h>=0 && h<=23 && m>=0 && m<=59)
            return true;
        
        return false;
    }
    void solve(int idx,string time,int &ans)
    {
        if(idx==time.length())
        {
            if(isValid(time))
            {
                ans++;
            }
            return;
        }
        
        if(time[idx]=='?')
        {
            for(char c='0';c<='9';c++)
            {
                time[idx]=c;
                solve(idx+1,time,ans);
                time[idx]='?';
            }
        }
        else
        {
            solve(idx+1,time,ans);
        }
    }
    int countTime(string time) {
        
        int ans=0;
        
        solve(0,time,ans);
        
        return ans;
        
        
    }
};