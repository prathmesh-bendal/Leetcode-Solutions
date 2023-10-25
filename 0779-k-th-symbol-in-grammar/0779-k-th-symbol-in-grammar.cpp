class Solution {
public:
    int solve(int n,int k)
    {
        if(n==1)
            return 0;
        int par=k/2;
        int val=solve(n-1,par);
        
        if(val==0)
        {
            if(k%2==0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
                
        }
        else
        {
            if(k%2==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }   
        }
    }
    int kthGrammar(int n, int k) {
        
        return solve(n,k-1);
        
        
    }
};