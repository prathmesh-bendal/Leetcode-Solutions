class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string> st(bank.begin(),bank.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int level=0;
        
        
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                string curr =q.front();
                q.pop();
                
                if(curr==end)
                    return level;
                
                
                for(auto c:"ACGT")
                {
                    for(int i=0;i<curr.length();i++)
                    {
                        if(curr[i]!=c)
                        {
                            string next=curr;
                            next[i]=c;
                            
                            if(visited.find(next)==visited.end() && st.find(next)!=st.end())
                            {
                                q.push(next);
                                visited.insert(next);
                            }
                        }
                    }
                }
                
            }
            level++;
        }
        
        return -1;
    }
};