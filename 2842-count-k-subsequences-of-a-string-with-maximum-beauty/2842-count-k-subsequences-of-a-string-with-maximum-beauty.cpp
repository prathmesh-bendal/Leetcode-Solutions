class Solution {
public:
    long long pow(long long x,long long n,int m)
    {
        if(n==0)
            return 1;
        
        if(n==1)
            return x;
        
        if(n%2==0)
        {
            long long y=pow(x,n/2,m);
            y=y%m;
            
            return (1LL*y*y)%m;
        }
        else
        {
            long long y=pow(x,(n-1)/2,m);
            y=y%m;
            y=y*y;
            y=y%m;
            y=y*x;
            y=y%m;
            
            return y;
        }
    }
    int nCr(int n,int r,int m)
    {
        long long num=1;
        long long den=1;
        int start=n-r+1;
        for(int i=1;i<=r;i++)
        {
            den=den*i;
            den=den%m;
            num=num*start;
            num=num%m;
            
            int g=__gcd(den,num);
            den=den/g;
            num=num/g;
            start++;
        }
        return num%m;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        
        
        unordered_map<char,int> freq;
        
        for(auto c:s)
        {
            freq[c]++;
        }
        if(k>freq.size())
            return 0;
        unordered_map<int,int> mp;
        
        for(auto it:freq)
        {
            mp[it.second]++;
        }
        
        vector<pair<int,int>> v;
        
        for(auto it:mp)
        {
            v.push_back({it.first,it.second});
        }
        
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        // for(auto p:v)
        // {
        //     cout<<p.first<<":"<<p.second<<endl;
        // }
        int m=1e9+7;
        int idx=0;
        long long ans=1;
        while(k>0)
        {
            if(k>=v[idx].second)
            {
                ans=ans*1LL*pow(v[idx].first,v[idx].second,m);
                ans=ans%m;
                k=k-v[idx].second;
            }
            else
            {
                ans=ans*1LL*nCr(v[idx].second,k,m);
                ans=ans%m;
                ans=ans*1LL*pow(v[idx].first,k,m);
                ans=ans%m;
                k=0;
            }
            idx++;
        }
        return ans;
    }
};