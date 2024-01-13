class Solution {
public:
    long long pow(long long x,long long n)
    {
        if(n==0)
            return 1LL;
        
        if(n%2==0)
        {
            long long y=pow(x,n/2);
            return y*y;
        }
        else
        {
            long long y=pow(x,(n-1)/2);
            
            return y*y*x;
        }
    }
    long long solve(string num,string &s,int limit)
    {
        if(num.length()<s.length())
            return 0;
        
        if(num.length()==s.length() && num<s)
            return 0;
        
        if(num.length()==s.length())
            return 1;
        
        
        if((num[0]-'0')>limit)
        {
            return 1LL*(limit+1)*pow(limit+1,1LL*num.length()-s.length()-1);
        }
        else
        {
            string rem=num.substr(1);
            return (num[0]-'0')*pow(limit+1,1LL*num.length()-s.length()-1)+solve(rem,s,limit);
        }
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        
        for(auto c:s)
        {
            if((c-'0')>limit)
                return 0;
        }
        
        
        string r=to_string(finish);
        string l=to_string(start-1);
        
         
        return solve(r,s,limit)-solve(l,s,limit);
    }
};