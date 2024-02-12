class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        
        int ans=INT_MAX;
    
        int i=0,j=0;
        int sum=0;

        while(j<v.size())
        {
            sum+=v[j];


            while(sum>=target)
            {
                sum-=v[i];
                ans=min(ans,j-i+1);
                i++;
            }
            j++;
        }
        if(ans==INT_MAX)
        return 0;
        return ans;
        
    }
};