class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string,int> mp;
        for(auto s:words)
            mp[s]++;
        
        
        for(auto i:mp)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
        
        int ans=0;
        bool used=false;
        for(auto i:mp)
        {
            string a=i.first;
            int count=i.second;
            string b="";
            b+=a[1];
            b+=a[0];
            
            if(a[0]==a[1])
            {
                if(count%2==0)
                {
                    ans+=count*2;
                }
                else
                {
                    ans+=(count-1)*2;
                }
                if(count%2==1 && used==false)
                {
                    ans+=2;
                    used=true;
                }
            }
            else
            {
                ans+=min(mp[a],mp[b])*2;
            }
                
        }
        return ans;
    }
};

/*
dd 5
aa 3
bb 3
cc 3


*/