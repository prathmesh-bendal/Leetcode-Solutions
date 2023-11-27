class Solution {
public:
    unordered_map<int,list<int>> mp;
    int dp[11][5001];
    int m=1e9+7;
    void setup()
    {
        mp[0].push_back(4);
        mp[0].push_back(6);
        
        mp[1].push_back(6);
        mp[1].push_back(8);
        
        mp[2].push_back(7);
        mp[2].push_back(9);
        
        mp[3].push_back(4);
        mp[3].push_back(8);
        
        mp[4].push_back(3);
        mp[4].push_back(9);
        mp[4].push_back(0);
        
        mp[6].push_back(1);
        mp[6].push_back(7);
        mp[6].push_back(0);
        
        mp[7].push_back(6);
        mp[7].push_back(2);
        
        mp[8].push_back(1);
        mp[8].push_back(3);
        
        mp[9].push_back(2);
        mp[9].push_back(4);
    }
    int solve(int num,int moves)
    {
        if(moves<=0)
        {
            return 0;
        }
        
        if(moves==1)
            return 1;
        
        if(dp[num][moves]!=-1)
        {
            
            return dp[num][moves];
        }
            
        long long ans=0;
        for(auto v:mp[num])
        {
            ans+=1LL*solve(v,moves-1);
            ans=ans%m;
        }
        
        return dp[num][moves]=ans;
          
    }
    int knightDialer(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 10;
        setup();
        memset(dp,-1,sizeof(dp));
        
        int ans=0;        
        for(int i=0;i<=9;i++)
        {
            ans+=1LL*solve(i,n);
            ans=ans%m;
        }
        
        
        return ans;
    }
};