class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        
        int n=dist.size();
        
        // dp[index][skips] (min required time to reach index i using j skips)
        vector<vector<double>> dp(n+1,vector<double>(n+1,1e9));
        
        // we are treating dist as 1 based index 
        
        // base case
        // to reach complete index 0 we need 0 steps 
        for(int i=0;i<=n;i++)
            dp[0][i]=0;
        
        
        double eps=0.000000001;
        //base case
        // to reach index i with 0 skips
        
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=ceil(dp[i-1][0]-eps)+1.0*dist[i-1]/speed;
            
        }
        
        
        
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                double skip=dp[i-1][j-1];
                
                double dontSkip=ceil(dp[i-1][j]-eps);
                
                dp[i][j]=1.0*dist[i-1]/speed+min(skip,dontSkip);
                
            }
        }
        
        // for(int i=0;i<=n;i++)
        // {
        //     cout<<dp[i][0]<<" ";
        // }
        for(int i=0;i<n;i++)
        {
            if(dp[n][i]<=hoursBefore)
                return i;
        }
        return -1;
        
      
        
    }
};