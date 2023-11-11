class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        long long ans=0;
        long long sum=0;
        
        
        int i=0,j=0;
        
        while(j<nums.size())
        {
            sum+=nums[j];
            int len=j-i+1;
            long long prod=1LL*len*sum;
            // cout<<"prod:"<<prod<<endl;
            while(prod>=k && i<=j)
            {
                // cout<<"hello"<<endl;
                sum-=nums[i];
                i++;
                len=j-i+1;
                prod=1LL*len*sum;;
            }
            // cout<<i<<"-"<<j<<endl;
            if(i<=j)
            {
                ans+=(j-i+1);
            }
            j++;
        }
        return ans;
    }
};