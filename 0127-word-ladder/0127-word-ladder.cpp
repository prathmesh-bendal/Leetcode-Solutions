class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
		
		if(start==end)
			return 0;
		set<string> words(wordList.begin(),wordList.end());
		
		queue<string> q;
		set<string> vis;
		
		q.push(start);
		vis.insert(start);
		
		int ans=0;
		
		while(q.size()>0)
		{
			
			
			
			int sz=q.size();

			while(sz--)
			{
				string curr=q.front();
				q.pop();
                
                if(curr==end)
				return ans+1;

				for(int i=0;i<curr.length();i++)
				{
					for(char c='a';c<='z';c++)
					{
						if(c!=curr[i])
						{
							string next=curr;
							next[i]=c;

							if(words.find(next)!=words.end() && vis.find(next)==vis.end())
							{
								q.push(next);
								vis.insert(next);
							}
						}
					}
				}
			}
			ans++;
		}
		return 0;
		
        
        
        
    }
};