class Solution {
public:
    vector<bool> col;
    set<int> diag,antiDiag;
    bool canPlace(int r,int c)
    {
        if(col[c]==true)
            return false;
        
        if(diag.find(c-r)!=diag.end())
            return false;
        
        if(antiDiag.find(r+c)!=antiDiag.end())
            return false;
        
        
        return true;
    }
    bool solve(int r,int n,vector<string> curr,vector<vector<string>> &ans)
    {
        if(r==n)
        {
            // curr[n-1].pop_back();
            ans.push_back(curr);
            return true;
        }
        
        string s="";
        for(int j=0;j<n;j++)
            s+=".";
        // s+=",";
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(canPlace(r,i))
            {
                col[i]=true;
                diag.insert(i-r);
                antiDiag.insert(r+i);
                s[i]='Q';
                curr.push_back(s);
                if(solve(r+1,n,curr,ans))
                {
                    flag=true;    
                }
                col[i]=false;
                diag.erase(i-r);
                antiDiag.erase(r+i);
                s[i]='.';
                curr.pop_back();
                
            }
            
        }
        return flag;
    }
    vector<vector<string>> solveNQueens(int n) {
        
        
        col=vector<bool>(n,false);
        diag.clear();
        antiDiag.clear();
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0,n,curr,ans);
        
        return ans;
        
    }
};