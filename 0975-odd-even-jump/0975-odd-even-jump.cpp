class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        
        int n=arr.size();
        vector<bool> even(n,false);
        vector<bool> odd(n,false);
        
        even[n-1]=true;
        odd[n-1]=true;
        
        unordered_map<int,int> indexmp;
        indexmp[arr[n-1]]=n-1;
        
        set<int> s;
        s.insert(arr[n-1]);
        int ans=1;
        for(int i=n-2;i>=0;i--)
        {
            auto it=s.lower_bound(arr[i]);
            if(it!=s.end())
            {
                int val=*it;
                int j=indexmp[val];
                odd[i]=even[j];
            }
            it=s.upper_bound(arr[i]);
            it--;
            if(*it<=arr[i])
            {
                int j=indexmp[*it];
                even[i]=odd[j];
            }
            
            if(odd[i])
                ans++;
            
            s.insert(arr[i]);
            indexmp[arr[i]]=i;
            
        }
        return ans;
        
    }
};